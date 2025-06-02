cmake_minimum_required (VERSION 3.21)

project(01WaveExercise LANGUAGES CXX)

include(../../../cmake/SetUpKokkos.cmake)

add_executable(proj01 main.cpp)
target_link_libraries(proj01 Kokkos::kokkos)

