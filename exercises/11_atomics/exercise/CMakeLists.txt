cmake_minimum_required (VERSION 3.21)

project(11Atomics LANGUAGES CXX)

include(../../../cmake/SetUpKokkos.cmake)

add_executable(
    exe11
    main.cpp
)

target_link_libraries(exe11 Kokkos::kokkos)
