cmake_minimum_required (VERSION 3.21)

project(01FirstProgramSolution LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/../../cmake/modules")

find_package(Kokkos REQUIRED)

add_executable(exe01solution main.cpp)
target_link_libraries(exe01solution Kokkos::kokkos)
add_test(
    NAME exe01solution
    COMMAND exe01solution
)
