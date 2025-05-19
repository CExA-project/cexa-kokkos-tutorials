cmake_minimum_required (VERSION 3.21)

project(01WaveSolution LANGUAGES CXX)

include(../../../cmake/SetUpKokkos.cmake)

add_executable(proj01solution main.cpp)
target_link_libraries(proj01solution Kokkos::kokkos)
add_test(
    NAME proj01solution
    COMMAND proj01solution --size 128 128 --time 5 --output-period 100 --print-period 100 --domain-length 10 10 --boundary 1
)
