cmake_minimum_required (VERSION 3.21)

project(05ParallelReduceExercise LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake/modules")

find_package(Kokkos REQUIRED)

add_executable(exe05 main.cpp)
target_link_libraries(exe05 Kokkos::kokkos)
