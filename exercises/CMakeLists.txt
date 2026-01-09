cmake_minimum_required (VERSION 3.21)

project(CexaKokkosTutorialsExercises LANGUAGES CXX)

enable_testing()

add_subdirectory(01_first_program)
add_subdirectory(02_basic_view)
add_subdirectory(03_deep_copy)
add_subdirectory(04_parallel_loop)
add_subdirectory(05_parallel_reduce)

add_subdirectory(10_profiling)
add_subdirectory(11_atomics)
