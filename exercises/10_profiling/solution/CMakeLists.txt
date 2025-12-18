cmake_minimum_required (VERSION 3.21)

project(10ProfilingSolution LANGUAGES CXX)

include(../../../cmake/SetUpKokkos.cmake)

add_executable(
    exe10solution
    main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../common/display.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../common/arguments.cpp
)
target_include_directories(
    exe10solution
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/../common
)
target_link_libraries(exe10solution Kokkos::kokkos)
add_test(
    NAME exe10solution
    COMMAND exe10solution 100 1e-2
)
