cmake_minimum_required (VERSION 3.12)
project(exe LANGUAGES CXX)

find_package(Kokkos REQUIRED)

add_executable(exe main.cpp)
target_link_libraries(exe Kokkos::kokkos)