cmake_minimum_required (VERSION 3.21)

project(03DeepCopyExercise LANGUAGES CXX)

include(../../../cmake/SetUpKokkos.cmake)

add_executable(exe03 main.cpp)
target_link_libraries(exe03 Kokkos::kokkos)
