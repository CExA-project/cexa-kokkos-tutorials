cmake_minimum_required (VERSION 3.21)

project(03DeepCopyExercise LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake/modules")

find_package(Kokkos REQUIRED)

add_executable(exe03 main.cpp)
target_link_libraries(exe03 Kokkos::kokkos)
