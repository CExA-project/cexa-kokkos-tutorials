#pragma once

#include <Kokkos_Core.hpp>

void display(const Kokkos::View<double ***> &field, const float ratioZ = 0.5);
