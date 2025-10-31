cmake_minimum_required (VERSION 3.21)

project(04ParallelLoopSolution LANGUAGES CXX)

include(../../../cmake/SetUpKokkos.cmake)

add_executable(exe04solution main.cpp)
target_link_libraries(exe04solution Kokkos::kokkos)
add_test(
    NAME exe04solution
    COMMAND exe04solution
)
