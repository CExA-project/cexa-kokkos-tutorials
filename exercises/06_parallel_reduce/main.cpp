#include <Kokkos_Core.hpp>
#include <iostream>

int main(int argc, char* argv[]) {

    Kokkos::initialize(argc, argv);
    {

        // _____________________________________________________
        // Parameters

        int Nx = 100;
        int Ny = 100;

        // _____________________________________________________
        // Read Nx, Ny from the command line

        if (argc >= 3) {
            Nx = std::atoi(argv[1]);
            Ny = std::atoi(argv[2]);
        }

        // _____________________________________________________
        // Create a 2D view of size Nx x Ny

        std::cout << "Creation of a 2D view `matrix` of size " << Nx << " x " << Ny << std::endl;

        // ... Create a 2D view of size Nx x Ny ...

        // _____________________________________________________
        // Initialize the vector using a parallel loop

        // ... Initialize the Matrix using Kokkos::parallel_for(

        Kokkos::fence();

        // _____________________________________________________
        // Compute the sum of the matrix

        // ... Compute the sum of the matrix

        Kokkos::fence();

        // ... Print the result ...

        // _____________________________________________________
        // Compute the maximum of the matrix

        // ... Compute the maximum of the matrix ...

        Kokkos::fence();

        // ... Print the result ...

    }
    
    Kokkos::finalize();
    
    return 0;
}
