cmake_minimum_required (VERSION 3.21)

project(01WaveExercise LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake/modules")

find_package(Kokkos REQUIRED)

add_executable(proj01 main.cpp)
target_link_libraries(proj01 Kokkos::kokkos)

