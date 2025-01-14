cmake_minimum_required (VERSION 3.21)

project(01WaveOpenMP LANGUAGES CXX)

find_package(OpenMP REQUIRED)

add_executable(proj01openmp main.cpp)
target_link_libraries(proj01openmp OpenMP::OpenMP_CXX)
add_test(
    NAME proj01openmp
    COMMAND proj01openmp --size 128 128 --time 5 --output-period 100 --print-period 100 --domain-length 10 10 --boundary 1
)
