cmake_minimum_required (VERSION 3.21)

project(02BasicViewSolution LANGUAGES CXX)

include(../../../cmake/SetUpKokkos.cmake)

add_executable(exe02solution main.cpp)
target_link_libraries(exe02solution Kokkos::kokkos)
add_test(
    NAME exe02solution
    COMMAND exe02solution
)
