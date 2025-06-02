cmake_minimum_required (VERSION 3.21)

project(03DeepCopySolution LANGUAGES CXX)

include(../../../cmake/SetUpKokkos.cmake)

add_executable(exe03solution main.cpp)
target_link_libraries(exe03solution Kokkos::kokkos)
add_test(
    NAME exe03solution
    COMMAND exe03solution
)
