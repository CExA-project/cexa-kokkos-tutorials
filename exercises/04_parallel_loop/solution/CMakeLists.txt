cmake_minimum_required (VERSION 3.21)

project(04ParallelLoopSolution LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/modules")

find_package(Kokkos REQUIRED)

add_executable(exe04solution main.cpp)
target_link_libraries(exe04solution Kokkos::kokkos)
