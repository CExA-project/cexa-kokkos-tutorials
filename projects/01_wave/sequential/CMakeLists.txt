cmake_minimum_required (VERSION 3.21)

project(01WaveSequential LANGUAGES CXX)

add_executable(proj01sequential main.cpp)
add_test(
    NAME proj01sequential
    COMMAND proj01sequential --size 128 128 --time 5 --output-period 100 --print-period 100 --domain-length 10 10 --boundary 1
)
