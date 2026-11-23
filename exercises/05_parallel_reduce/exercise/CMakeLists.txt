cmake_minimum_required (VERSION 3.22)

project(05ParallelReduceExercise LANGUAGES CXX)

include(../../../cmake/SetUpKokkos.cmake)

add_executable(exe05 main.cpp)
target_link_libraries(exe05 Kokkos::kokkos)
