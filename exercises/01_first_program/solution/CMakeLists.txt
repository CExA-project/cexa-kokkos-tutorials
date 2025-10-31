cmake_minimum_required (VERSION 3.21)

project(01FirstProgramSolution LANGUAGES CXX)

include(../../../cmake/SetUpKokkos.cmake)

add_executable(exe01solution main.cpp)
target_link_libraries(exe01solution Kokkos::kokkos)
add_test(
    NAME exe01solution
    COMMAND exe01solution
)
