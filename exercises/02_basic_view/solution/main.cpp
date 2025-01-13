#include <iostream>
#include <Kokkos_Core.hpp>

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

        // Create a 3D view of size Nx x Ny x Nz
        Kokkos::View<double***> matrix("matrix", Nx, Ny, Nz);

        // Get the rank
        size_t rank = matrix.rank();

        std::cout << "Matrix rank: " << rank << std::endl;

        // Get the extent of the view
        size_t extent[3];
        extent[0] = matrix.extent(0);
        extent[1] = matrix.extent(1);
        extent[2] = matrix.extent(2);

        std::cout << "Matrix extent: " << extent[0] << " x " << extent[1] << " x " << extent[2] << std::endl;

        // Get the stride of the view

        size_t stride[3];
        stride[0] = matrix.stride(0);
        stride[1] = matrix.stride(1);
        stride[2] = matrix.stride(2);

        std::cout << "Matrix stride: " << stride[0] << " x " << stride[1] << " x " << stride[2] << std::endl;
    }
    Kokkos::finalize();

    return 0;
}
