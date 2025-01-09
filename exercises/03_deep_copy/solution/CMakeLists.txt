cmake_minimum_required (VERSION 3.21)

project(03DeepCopySolution LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/modules")

find_package(Kokkos REQUIRED)

add_executable(exe03solution main.cpp)
target_link_libraries(exe03solution Kokkos::kokkos)
add_test(
    NAME exe03solution
    COMMAND exe03solution
)
