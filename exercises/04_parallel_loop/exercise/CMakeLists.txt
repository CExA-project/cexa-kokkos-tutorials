cmake_minimum_required (VERSION 3.21)

project(04ParallelLoopExercise LANGUAGES CXX)

include(../../../cmake/SetUpKokkos.cmake)

add_executable(exe04 main.cpp)
target_link_libraries(exe04 Kokkos::kokkos)
