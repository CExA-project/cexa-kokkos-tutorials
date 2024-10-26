# Kokkos-cexa-tutorial

![CI](https://github.com/CExA-project/cexa-kokkos-tutorials/actions/workflows/courses.yml/badge.svg)
![CI](https://github.com/CExA-project/cexa-kokkos-tutorials/actions/workflows/exercises.yml/badge.svg)
![CI](https://github.com/CExA-project/cexa-kokkos-tutorials/actions/workflows/projects.yml/badge.svg)

Courses

- [Introduction to Kokkos](courses/01_beginners/README.md)

Exercises:

- [Exercise 1: Compiling Kokkos](exercises/01_compiling_kokkos/README.md)
- [Exercise 2: First Kokkos Program](exercises/02_first_program/README.md)
- [Exercise 3: Learn how to use and manage basic Kokkos View](exercises/03_basic_view/README.md)
- [Exercise 4: Mirror view and deep copy](exercises/04_deep_copy/README.md)
- [Exercise 5: Parallel Loop](exercises/05_parallel_loop/README.md)
- [Exercise 6: Parallel Reduce](exercises/06_parallel_reduce/README.md)

Projects:

- [Project 1: Wave Propagation](projects/wave/README.md)

## Compile the tutorials

To compile the tutorials, you need a working Tex environment.

```bash
xelatex -shell-escape main.tex
```