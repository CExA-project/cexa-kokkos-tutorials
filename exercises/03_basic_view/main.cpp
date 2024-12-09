#include <Kokkos_Core.hpp>
#include <iostream>

int main(int argc, char* argv[]) {

    Kokkos::initialize(argc, argv);
    {

        int Nx = 10;
        int Ny = 15;
        int Nz = 20;

        // Read Nx, Ny, Nz from the command line
        if (argc == 4) {
            Nx = std::atoi(argv[1]);
            Ny = std::atoi(argv[2]);
            Nz = std::atoi(argv[3]);
        }

        // Create a 3D view of size Nx x Ny x Nz and type `double`
        // ...

        // Get the rank
        // ...

        // Get the extent of the view
        // ...

        // Get the stride of the view
        // ...
    }
    
    Kokkos::finalize();
    
    return 0;
}
