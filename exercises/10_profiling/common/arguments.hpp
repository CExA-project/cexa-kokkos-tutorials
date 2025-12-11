#pragma once

#include <cstdlib>

struct Arguments {
    std::size_t iterationMax = 100'000;
    double residualMin = 1e-8;
    int size = 100;

    Arguments(){};
    Arguments(const std::size_t iterationMax, const double residualMin,
              const int size)
        : iterationMax{iterationMax}, residualMin{residualMin}, size{size} {};
    Arguments(int argc, char *argv[]);

    void describe();
};

void printUsage();
