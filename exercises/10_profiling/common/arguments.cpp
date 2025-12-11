#include "arguments.hpp"

#include <cstring>
#include <iostream>
#include <stdexcept>

void printUsage() {
    std::cout << R"(exe10 [ITERATION_MAX [RESIDUAL_MIN [SIZE]]] [-h]

Solve the 3D heat equation.

    ITERATION_MAX
        Maximal number of iterations. Default to 100000.
    RESIDUAL_MIN
        Minimal value of the residual. Default to 1e-8.
    SIZE
        Size of the problem for one dimension (will be replicated for the other dimensions). Default to 100.

    -h
        Display this help message and exit.
)";
}

Arguments::Arguments(int argc, char* argv[]) {
    // search for help command
    for (std::size_t i = 1; i < argc; i++) {
        if (std::strcmp(argv[i], "-h") == 0) {
            printUsage();
            std::exit(EXIT_SUCCESS);
        }
    }

    // check number of arguments
    if (argc > 4) {
        std::cerr << "Too many arguments" << std::endl;
        printUsage();
        std::exit(EXIT_FAILURE);
    }

    try {
        // first argument for iterations
        if (argc > 1) {
            iterationMax = std::stoi(argv[1]);
        }
        // second argument for residual
        if (argc > 2) {
            residualMin = std::stod(argv[2]);

            if (residualMin <= 0) {
                throw std::invalid_argument("residualMin sign error");
            }
        }
        // third argument for size
        if (argc > 3) {
            size = std::stoi(argv[3]);

            if (size <= 0) {
                throw std::invalid_argument("size sign error");
            }
            if (size < 2) {
                throw std::invalid_argument("size too small");
            }
        }
    } catch (const std::invalid_argument& error) {
        std::cerr << "Error processing arguments: " << error.what()
                  << std::endl;
        printUsage();
        std::exit(EXIT_FAILURE);
    }
}

void Arguments::describe() {
    std::cout << "Iteration max: " << iterationMax << std::endl;
    std::cout << "Residual min: " << residualMin << std::endl;
    std::cout << "Size in one direction: " << size << std::endl;
    std::cout << "Size in total: " << size * size * size << std::endl;
}

