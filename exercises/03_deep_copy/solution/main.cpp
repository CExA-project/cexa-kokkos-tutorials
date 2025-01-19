#include <iostream>
#ifdef __unix__
#include <sys/resource.h>
#endif
#include <Kokkos_Core.hpp>

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
        struct rusage usage;

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

        std::cout << " 2) Creating the 3D view `mirror` with create_mirror_view()" << std::endl;
        Kokkos::View<double***>::HostMirror mirror = Kokkos::create_mirror_view(matrix);

        extent[0] = mirror.extent(0);
        extent[1] = mirror.extent(1);
        extent[2] = mirror.extent(2);

        stride[0] = mirror.stride(0);
        stride[1] = mirror.stride(1);
        stride[2] = mirror.stride(2);

        std::cout << " - Mirror extent: " << extent[0] << " x " << extent[1] << " x " << extent[2] << std::endl;
        std::cout << " - Mirror stride: " << stride[0] << " x " << stride[1] << " x " << stride[2] << std::endl;

        // Initialize the matrix

        for (int i = 0; i < Nx; i++) {
            for (int j = 0; j < Ny; j++) {
                for (int k = 0; k < Nz; k++) {
                    mirror(i, j, k) = i + j + k;
                }
            }
        }

        // _____________________________________________________
        // Deep copy the mirror view to the matrix

        timer_start = timer.seconds();
        Kokkos::deep_copy(matrix, mirror);
        timer_stop = timer.seconds();

        std::cout << "Time to deep copy mirror to matrix: " << timer_stop - timer_start << std::endl;

#ifdef __unix__
        getrusage(RUSAGE_SELF, &usage);
        std::cout << "Total memory usage after `create_mirror_view`: " << usage.ru_maxrss << " KB" << std::endl;
#endif

        // _____________________________________________________
        // New mirror view

        std::cout << " 3) Creating the 3D view `mirror_2` with create_mirror()" << std::endl;
        Kokkos::View<double***>::HostMirror mirror_2 = Kokkos::create_mirror(matrix);

        // _____________________________________________________
        // Deep copy the matrix to the new mirror view

        timer_start = timer.seconds();
        Kokkos::deep_copy(mirror_2, matrix);
        timer_stop = timer.seconds();

        std::cout << "Time to deep copy matrix to mirror_2: " << timer_stop - timer_start << std::endl;

#ifdef __unix__
        getrusage(RUSAGE_SELF, &usage);
        std::cout << "Total memory usage after `create_mirror`: " << usage.ru_maxrss << " KB" << std::endl;
#endif

        // _____________________________________________________
        // Compare mirror and mirror_2

        double error = 0.0;

        for (int i = 0; i < Nx; i++) {
            for (int j = 0; j < Ny; j++) {
                for (int k = 0; k < Nz; k++) {
                    error += std::abs(mirror(i, j, k) - mirror_2(i, j, k));
                }
            }
        }

        std::cout << "Error: " << error << std::endl;

    }
    Kokkos::finalize();

    return 0;
}
