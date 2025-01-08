#include <Kokkos_Core.hpp>
#ifdef __unix__
#include <sys/resource.h>
#endif
#include <iostream>

int main(int argc, char* argv[]) {

    Kokkos::initialize(argc, argv);
    {

        // _____________________________________________________
        // Parameters

        int Nx = 10;
        int Ny = 15;
        int Nz = 20;

        Kokkos::Timer timer;
        double timer_start, timer_stop;
#ifdef __unix__
        struct rusage usage;
#endif

        // _____________________________________________________
        // Read Nx, Ny, Nz from the command line
        if (argc == 4) {
            Nx = std::atoi(argv[1]);
            Ny = std::atoi(argv[2]);
            Nz = std::atoi(argv[3]);
        }

        // _____________________________________________________
        // Create a 3D view of size Nx x Ny x Nz

        std::cout << " 1) Creating the 3D view `matrix` of size " << Nx << " x " << Ny << " x " << Nz << std::endl;

        Kokkos::View<double***> matrix("matrix", Nx, Ny, Nz);

        // Get the rank
        size_t rank = matrix.rank();

        std::cout << " - Matrix rank: " << rank << std::endl;

        // Get the extent of the view
        size_t extent[3];
        extent[0] = matrix.extent(0);
        extent[1] = matrix.extent(1);
        extent[2] = matrix.extent(2);

        std::cout << " - Matrix extent: " << extent[0] << " x " << extent[1] << " x " << extent[2] << std::endl;

        // Get the stride of the view

        size_t stride[3];
        stride[0] = matrix.stride(0);
        stride[1] = matrix.stride(1);
        stride[2] = matrix.stride(2);

        std::cout << " - Matrix stride: " << stride[0] << " x " << stride[1] << " x " << stride[2] << std::endl;

#ifdef __unix__
        getrusage(RUSAGE_SELF, &usage);
        std::cout << "Total memory usage: " << usage.ru_maxrss << " KB" << std::endl;
#endif

        // _____________________________________________________
        // Create a mirror view of the matrix using create_mirror_view

        // ...

#ifdef __unix__
        getrusage(RUSAGE_SELF, &usage);
        std::cout << "Total memory usage: " << usage.ru_maxrss << " KB" << std::endl;
#endif

        // Initialize the matrix

        // ...

        // _____________________________________________________
        // Deep copy the mirror view to the matrix

        // ...

        // _____________________________________________________
        // New mirror view

        // ...

        // _____________________________________________________
        // Deep copy the matrix to the new mirror view

        // ...

#ifdef __unix__
        getrusage(RUSAGE_SELF, &usage);
        std::cout << "Total memory usage: " << usage.ru_maxrss << " KB" << std::endl;
#endif

        // _____________________________________________________
        // Compare mirror and mirror_2

        // ...


    }
    Kokkos::finalize();

    return 0;
}
