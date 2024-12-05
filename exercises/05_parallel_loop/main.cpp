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

        // ... Create a 1D view of size N ...

        // _____________________________________________________
        // Initialize the vector using a parallel loop

        // ... Initialize the vector using a parallel loop ...

        // ... Fence ...

        // _____________________________________________________
        // Create a mirror view of the vector

        // ... Create a mirror view of the vector ...

        // _____________________________________________________
        // Deep copy the vector to the mirror view

        // ... Deep copy the vector to the mirror view ...

        // _____________________________________________________
        // Check the result

        // ... Check the result ...
    }
    
    Kokkos::finalize();
    
    return 0;
}
