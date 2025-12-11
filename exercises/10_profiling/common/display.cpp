#include "display.hpp"

#include <cmath>
#include <iostream>

int getSizeScreen(const int size, const int sizeTarget, const float adjust = 0.1, const int maxAdjustSteps = 1000) {
    if (size <= sizeTarget) {
        return size;
    }

    // adjust the screen size so it is more a submultiple of the initial size
    int sizeScreen = size / std::ceil(size * 1.0 / sizeTarget);
    for (int i = 0; i < maxAdjustSteps; i++) {
        float ratio = size * 1.0 / sizeScreen;
        if (std::abs(ratio - std::floor(ratio)) <= adjust) {
            return sizeScreen;
        }
        sizeScreen++;
    }

    // if the maximum number of adjust steps is reached
    return sizeScreen;
}

void display(const Kokkos::View<double ***> &field, const float ratioZ) {
    const int sizeX = field.extent(0);
    const int sizeY = field.extent(1);
    const int sizeZ = field.extent(2);
    const int sliceIndexZ = sizeZ * ratioZ;

    auto slice = Kokkos::subview(field, Kokkos::ALL, Kokkos::ALL, sliceIndexZ);

    auto sliceHost = Kokkos::create_mirror_view(slice);
    Kokkos::deep_copy(sliceHost, slice);

    // resize to the size of the screen
    const int sizeXScreen = getSizeScreen(sizeX, 30);
    const int sizeYScreen = getSizeScreen(sizeY, 15);
    const int ratioX = sizeX / sizeXScreen;
    const int ratioY = sizeY / sizeYScreen;

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
    std::cout << "y" << std::endl;
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
    std::cout << "┘ x" << std::endl;
}
