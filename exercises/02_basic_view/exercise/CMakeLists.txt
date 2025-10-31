cmake_minimum_required (VERSION 3.21)

project(02BasicViewExercise LANGUAGES CXX)

include(../../../cmake/SetUpKokkos.cmake)

add_executable(exe02 main.cpp)
target_link_libraries(exe02 Kokkos::kokkos)
