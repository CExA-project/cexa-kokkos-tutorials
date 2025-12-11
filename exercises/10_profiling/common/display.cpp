#include "display.hpp"

#include <cmath>
#include <iostream>

void display(const Kokkos::View<double ***> &field, const float ratioZ) {
    const int sizeX = field.extent(0);
    const int sizeY = field.extent(1);
    const int sizeZ = field.extent(2);
    const int sliceIndexZ = sizeZ * ratioZ;

    auto slice = Kokkos::subview(field, Kokkos::ALL, Kokkos::ALL, sliceIndexZ);

    auto sliceHost = Kokkos::create_mirror_view(slice);
    Kokkos::deep_copy(sliceHost, slice);

    // resize to the size of the screen
    const int sizeXScreen = std::min(30, sizeX);
    const int sizeYScreen = std::min(15, sizeY / 2);
    const float ratioX = sizeX / sizeXScreen;
    const float ratioY = sizeY / sizeYScreen;

    Kokkos::View<double **, Kokkos::DefaultHostExecutionSpace> sliceHostScreen(
        "slice host screen", sizeXScreen, sizeYScreen);

    // resize by taking the average of the skipped elements
    for (int i = 0; i < sizeXScreen; i++)
        for (int j = 0; j < sizeYScreen; j++)
            for (int iLocal = 0; iLocal < ratioX; iLocal++)
                for (int jLocal = 0; jLocal < ratioY; jLocal++) {
                    sliceHostScreen(i, j) +=
                        sliceHost(i * ratioX + iLocal, j * ratioY + jLocal) /
                        (ratioX * ratioY);
                }

    std::cout << "Slice at z = " << sliceIndexZ << std::endl;
    std::cout << "┌";
    for (int j = 0; j < sizeXScreen; j++) std::cout << "─";
    std::cout << "┐" << std::endl;

    for (int j = 0; j < sizeYScreen; j++) {
        std::cout << "│";
        for (int i = 0; i < sizeXScreen; i++) {
            int value = sliceHostScreen(i, j) * 5;
            if (value < 1) {
                std::cout << " ";
            } else if (value < 2) {
                std::cout << "░";
            } else if (value < 3) {
                std::cout << "▒";
            } else if (value < 4) {
                std::cout << "▓";
            } else {
                std::cout << "█";
            }
        }
        std::cout << "│" << std::endl;
    }

    std::cout << "└";
    for (int j = 0; j < sizeXScreen; j++) std::cout << "─";
    std::cout << "┘" << std::endl;
}
