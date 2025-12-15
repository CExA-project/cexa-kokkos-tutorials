#include <Kokkos_Core.hpp>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstring>
#include <iostream>

// custom headers for the exercise
#include "arguments.hpp"
#include "display.hpp"

/**
 * Solve the heat equation iteratively.
 * @param[in] sizeX Number of elements in the X dimension.
 * @param[in] sizeY Number of elements in the Y dimension.
 * @param[in] sizeZ Number of elements in the Z dimension.
 * @param[in] iterationMax Maximum number of iterations to run.
 * @param[in] residualMin Minimum residual to reach during the iterative resolution.
 */
void compute(const int sizeX, const int sizeY, const int sizeZ,
             const std::size_t iterationMax, const double residualMin) {
    /**
     * Start initialization
     */
    Kokkos::Profiling::pushRegion("preparation");

    // fields
    Kokkos::View<double ***> field("field", sizeX, sizeY, sizeZ);
    Kokkos::View<double ***> fieldTemp("field temp", sizeX, sizeY, sizeZ);

    // initialize hot
    Kokkos::parallel_for(
        "initialize hot",
        Kokkos::MDRangePolicy<Kokkos::Rank<3>>({0, 0, 0}, {1, sizeY, sizeZ}),
        KOKKOS_LAMBDA(const int i, const int j, const int k) {
            field(i, j, k) = 1;
        });

    // initialize cold
    Kokkos::parallel_for(
        "initialize cold",
        Kokkos::MDRangePolicy<Kokkos::Rank<3>>({1, 0, 0},
                                               {sizeX, sizeY, sizeZ}),
        KOKKOS_LAMBDA(const int i, const int j, const int k) {
            field(i, j, k) = 0;
        });

    // wait for all initializations to complete
    Kokkos::fence("wait for initialize hot and cold");

    /**
     * End initialization
     */
    Kokkos::Profiling::popRegion();

    /**
     * Start computation
     */
    Kokkos::Profiling::pushRegion("computation");

    // iteration loop
    std::size_t iteration;
    double residual = 10;
    for (iteration = 0; iteration < iterationMax; iteration++) {
        // check residual
        if (residual <= residualMin) break;

        // compute new field
        Kokkos::parallel_for(
            "compute new field",
            Kokkos::MDRangePolicy<Kokkos::Rank<3>>(
                {1, 1, 1}, {sizeX - 1, sizeY - 1, sizeZ - 1}),
            KOKKOS_LAMBDA(const int i, const int j, const int k) {
                fieldTemp(i, j, k) =
                    field(i, j, k) +
                    0.1 * (-6 * field(i, j, k) + field(i + 1, j, k) +
                           field(i - 1, j, k) + field(i, j + 1, k) +
                           field(i, j - 1, k) + field(i, j, k + 1) +
                           field(i, j, k - 1));
            });

        // wait for compute new field
        Kokkos::fence("wait for compute new field");

        // compute residual
        residual = 0;
        Kokkos::parallel_reduce(
            "compute residual",
            Kokkos::MDRangePolicy<Kokkos::Rank<3>>(
                {1, 1, 1}, {sizeX - 1, sizeY - 1, sizeZ - 1}),
            KOKKOS_LAMBDA(const int i, const int j, const int k,
                          double &residual) {
                residual = Kokkos::max(
                    residual, Kokkos::abs(fieldTemp(i, j, k) - field(i, j, k)));
            },
            Kokkos::Max<double>(residual));

        // swap fields
        Kokkos::parallel_for(
            "swap fields",
            Kokkos::MDRangePolicy<Kokkos::Rank<3>>(
                {1, 1, 1}, {sizeX - 1, sizeY - 1, sizeZ - 1}),
            KOKKOS_LAMBDA(const int i, const int j, const int k) {
                field(i, j, k) = fieldTemp(i, j, k);
            });

        // wait for swap fields
        Kokkos::fence("wait for swap fields");
    }

    /**
     * End computation
     */
    Kokkos::Profiling::popRegion();

    if (iteration < iterationMax) {
        std::cout << "Converged with residual " << residual << " after "
                  << iteration << " iterations" << std::endl;
    } else {
        std::cout << "Did not converge after " << iterationMax
                  << " iterations, final residual is " << residual << std::endl;
    }

    /**
     * Start analysis
     */
    Kokkos::Profiling::pushRegion("display");

    display(field);

    Kokkos::Profiling::popRegion();

    /**
     * End analysis
     */
}

int main(int argc, char *argv[]) {
    Arguments arguments(argc, argv);
    arguments.describe();

    Kokkos::initialize(argc, argv);
    {
        compute(arguments.size, arguments.size, arguments.size,
                arguments.iterationMax, arguments.residualMin);
    }
    Kokkos::finalize();

    return 0;
}
