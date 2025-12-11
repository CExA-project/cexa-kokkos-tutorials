#pragma once

#include <cstdlib>

struct Arguments {
    int size = 100;
    double residualMin = 1e-8;
    std::size_t iterationMax = 100'000;

    Arguments(){};
    Arguments(const int size, const double residualMin,
              const std::size_t iterationMax)
        : size{size}, residualMin{residualMin}, iterationMax{iterationMax} {};
    Arguments(int argc, char *argv[]);

    void describe();
};

void printUsage();
