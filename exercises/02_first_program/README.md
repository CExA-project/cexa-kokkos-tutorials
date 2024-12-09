# Exercise 2: First Kokkos Program

In this exercise, you will write and compile your first Kokkos program. The goal is to get familiar with the compiling process.

## Step 1: Simple Kokkos program

- Open the file `main.cpp`, initialize and finalize Kokkos. Do not forget to add the header.
- Add the function `Kokkos::print_configuration` to print the configuration of Kokkos.

## Step 2: Compile the program with the serial backend

- Compile your program using your Serial Kokkos installation. You can use the following commands:

```bash
cmake -DCMAKE_VERBOSE_MAKEFILE=ON -DKokkos_ROOT=<path to your Kokkos> ./
make
```

- Run the program and check the output.

## Step 3: Compile the program with the OpenMP backend

- Recompile your program using the OpenMP Kokkos installation.

- Run the program and check the output.

For instance if you have an Apple computer and you are using the Clang compiler, you should get something like this:

```bash
  Kokkos Version: 4.4.0
Compiler:
  KOKKOS_COMPILER_APPLECC: 6000
Architecture:
  CPU architecture: none
  Default Device: N6Kokkos6OpenMPE
  GPU architecture: none
  platform: 64bit
Atomics:
Vectorization:
  KOKKOS_ENABLE_PRAGMA_IVDEP: no
  KOKKOS_ENABLE_PRAGMA_LOOPCOUNT: no
  KOKKOS_ENABLE_PRAGMA_UNROLL: no
  KOKKOS_ENABLE_PRAGMA_VECTOR: no
Memory:
Options:
  KOKKOS_ENABLE_ASM: no
  KOKKOS_ENABLE_CXX17: yes
  KOKKOS_ENABLE_CXX20: no
  KOKKOS_ENABLE_CXX23: no
  KOKKOS_ENABLE_CXX26: no
  KOKKOS_ENABLE_DEBUG_BOUNDS_CHECK: no
  KOKKOS_ENABLE_HWLOC: no
  KOKKOS_ENABLE_LIBDL: yes
Host Parallel Execution Space:
  KOKKOS_ENABLE_OPENMP: yes

OpenMP Runtime Configuration:
Kokkos::OpenMP thread_pool_topology[ 1 x 10 x 1 ]
```
