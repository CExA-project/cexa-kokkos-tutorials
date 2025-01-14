cmake_minimum_required (VERSION 3.21)

project(05ParallelReduceSolution LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake/modules")

find_package(Kokkos REQUIRED)

add_executable(exe05solution main.cpp)
target_link_libraries(exe05solution Kokkos::kokkos)
add_test(
    NAME exe05solution
    COMMAND exe05solution
)
