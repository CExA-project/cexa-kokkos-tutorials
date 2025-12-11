cmake_minimum_required (VERSION 3.21)

project(10ProfilingExercise LANGUAGES CXX)

include(../../../cmake/SetUpKokkos.cmake)

add_executable(
    exe10
    main.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../common/display.cpp
    ${CMAKE_CURRENT_LIST_DIR}/../common/arguments.cpp
)
target_include_directories(
    exe10
    PRIVATE
        ${CMAKE_CURRENT_LIST_DIR}/../common
)
target_link_libraries(exe10 Kokkos::kokkos)
