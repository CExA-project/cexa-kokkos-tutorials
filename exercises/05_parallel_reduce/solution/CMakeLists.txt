cmake_minimum_required (VERSION 3.21)

project(05ParallelReduceSolution LANGUAGES CXX)

include(../../../cmake/SetUpKokkos.cmake)

add_executable(exe05solution main.cpp)
target_link_libraries(exe05solution Kokkos::kokkos)
add_test(
    NAME exe05solution
    COMMAND exe05solution
)
