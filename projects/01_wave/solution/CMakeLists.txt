cmake_minimum_required (VERSION 3.21)

project(01WaveSolution LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake/modules")

find_package(Kokkos REQUIRED)

add_executable(proj01solution main.cpp)
target_link_libraries(proj01solution Kokkos::kokkos)
add_test(
    NAME proj01solution
    COMMAND proj01solution --size 128 128 --time 5 --output-period 100 --print-period 100 --domain-length 10 10 --boundary 1
)
