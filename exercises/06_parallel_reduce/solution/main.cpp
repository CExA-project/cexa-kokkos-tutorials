#include <Kokkos_Core.hpp>
#include <iostream>

int main(int argc, char* argv[]) {

    Kokkos::initialize(argc, argv);
    {

        // _____________________________________________________
        // Parameters

        int Nx = 100;
        int Ny = 100;
        Kokkos::Timer timer;

        // _____________________________________________________
        // Read Nx, Ny, Nz from command line

        if (argc > 1) {
            Nx = std::atoi(argv[1]);
            Ny = std::atoi(argv[2]);
        }

        // _____________________________________________________
        // Create a 2D view of size Nx x Ny

        std::cout << " Creation of a 2D view `matrix` of size " << Nx << " x " << Ny << std::endl;

        Kokkos::View<double**> matrix("matrix", Nx, Ny);

        // _____________________________________________________
        // Initialize the vector using a parallel loop

        Kokkos::parallel_for("Initialize", Kokkos::MDRangePolicy<Kokkos::DefaultExecutionSpace, Kokkos::Rank<2>>({0,0}, {Nx, Ny}),
        KOKKOS_LAMBDA(const int i, const int j) {
            matrix(i,j) = i + j;
        });

        Kokkos::fence();

        // _____________________________________________________
        // Compute the sum of the matrix

        auto sum_start = timer.seconds();
    
        double sum = 0;
        Kokkos::parallel_reduce("Compute sum",
        Kokkos::MDRangePolicy<Kokkos::DefaultExecutionSpace, Kokkos::Rank<2>>({0,0}, {Nx, Ny}),
        KOKKOS_LAMBDA(const int i, const int j, double& lsum) {
            lsum += matrix(i,j);
        }, sum);

        auto sum_stop = timer.seconds();

        std::cout << " Sum of the matrix: " << sum 
                  << " (computed in " << sum_stop - sum_start << " s)"
                  << std::endl;

        // _____________________________________________________
        // Compute the maximum of the matrix

        double max;

        auto max_start = timer.seconds();

        Kokkos::parallel_reduce( "Max",
        Kokkos::MDRangePolicy<Kokkos::DefaultExecutionSpace, Kokkos::Rank<2>>({0,0}, {Nx, Ny}),
        KOKKOS_LAMBDA (const int i, const int j, double& lmax) {
            if (matrix(i,j) > lmax) {
                lmax = matrix(i,j);
            }
        }, Kokkos::Max<double>(max));

        auto max_stop = timer.seconds();

        std::cout << " Max value: " << max 
                  << " (computed in " << max_stop - max_start << " s)"
                  << std::endl;

    }
    
    Kokkos::finalize();
    
    return 0;
}