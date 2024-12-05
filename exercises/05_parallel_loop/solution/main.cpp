#include <Kokkos_Core.hpp>
#include <iostream>

int main(int argc, char* argv[]) {

    Kokkos::initialize(argc, argv);
    {

        // _____________________________________________________
        // Parameters

        int N = 100;

        Kokkos::Timer timer;
        double timer_start = 0;
        double timer_stop  = 0;

        // _____________________________________________________
        // Read Nx from the command line

        if (argc > 1) {
            N = std::atoi(argv[1]);
        }

        // _____________________________________________________
        // Create a 1D view of size Nx

        std::cout << "Creation the 1D view `vector` of size " << N << std::endl;

        Kokkos::View<double*> vector("vector", N);

        // _____________________________________________________
        // Initialize the vector using a parallel loop

        timer_start = timer.seconds();

        Kokkos::parallel_for("Initialize", N, KOKKOS_LAMBDA(const int i) {
            vector(i) = i;
        });

        Kokkos::fence();

        timer_stop = timer.seconds();

        std::cout << "Time to initialize the vector: " << timer_stop - timer_start << std::endl;

        // _____________________________________________________
        // Create a mirror view of the vector

        Kokkos::View<double*>::HostMirror mirror = Kokkos::create_mirror_view(vector);

        // _____________________________________________________
        // Deep copy the vector to the mirror view

        timer_start = timer.seconds();

        Kokkos::deep_copy(mirror, vector);

        timer_stop = timer.seconds();

        std::cout << "Time to deep copy vector from Host to Device: " << timer_stop - timer_start << std::endl;

        // _____________________________________________________
        // Check the result

        double error = 0.0;

        for (int i = 0; i < N; i++) {
            error += std::abs(static_cast<double>(i) - mirror(i));
        }

        std::cout << "Error: " << error << std::endl;

    }
    
    Kokkos::finalize();
    
    return 0;
}
