cmake_minimum_required (VERSION 3.21)

project(11Atomics LANGUAGES CXX)

include(../../../cmake/SetUpKokkos.cmake)

add_executable(
    exe11solution
    main.cpp
)
target_include_directories(
    exe11solution
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/../common
)
target_link_libraries(exe11solution Kokkos::kokkos)
