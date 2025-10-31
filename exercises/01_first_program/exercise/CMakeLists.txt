cmake_minimum_required (VERSION 3.21)

project(01FirstProgramExercise LANGUAGES CXX)

include(../../../cmake/SetUpKokkos.cmake)

add_executable(exe01 main.cpp)
target_link_libraries(exe01 Kokkos::kokkos)
