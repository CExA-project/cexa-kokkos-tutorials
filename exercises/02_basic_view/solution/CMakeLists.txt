cmake_minimum_required (VERSION 3.21)

project(02BasicViewSolution LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake/modules")

find_package(Kokkos REQUIRED)

add_executable(exe02solution main.cpp)
target_link_libraries(exe02solution Kokkos::kokkos)
add_test(
    NAME exe02solution
    COMMAND exe02solution
)
