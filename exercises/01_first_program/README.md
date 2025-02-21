# Exercise 1: First Kokkos Program

In this exercise, you will write and compile your first Kokkos program.
The goal is to get familiar with the compiling process.

## Step 1: Simple Kokkos program

In `exercise`, open the file `main.cpp`, initialize and finalize Kokkos.
Do not forget to add the header.

Add a call to the `Kokkos::print_configuration` function to print the configuration of Kokkos.

## Step 2: Compile the program with the serial backend

Compile your program using the serial backend.
You can use the following commands:

```sh
cd exercise
cmake -B build_serial
cmake --build build_serial
```

If you have already installed Kokkos in exercise 0, then you can use the following commands instead:

```sh
cd exercise
cmake -B build_serial \
    -DKokkos_ROOT=path/to/kokkos/serial/install
cmake --build build_serial
```

Run the program and check the output:

```sh
build_serial/exe01
```

## Step 3: Compile the program with the OpenMP backend

Recompile your program using the OpenMP backend.
You can use the following commands:

```sh
cmake -B build_openmp \
    -DKokkos_ENABLE_OPENMP=ON
cmake --build build_openmp
```

If you have already installed Kokkos in exercise 0, then you can use the following commands instead:

```sh
cd exercise
cmake -B build_openmp \
    -DKokkos_ROOT=path/to/kokkos/openmp/install
cmake --build build_openmp
```

Run the program and check the output:

```sh
build_openmp/exe01
```

For instance if you are on Linux and are using GCC, you should get something like this:

```log
  Kokkos Version: 4.5.1
Compiler:
  KOKKOS_COMPILER_GNU: 1140
Architecture:
  CPU architecture: none
  Default Device: OpenMP
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
  KOKKOS_ENABLE_ASM: yes
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
Kokkos::OpenMP thread_pool_topology[ 1 x 20 x 1 ]
```

If you have an Apple computer and you are using the Clang compiler, you should get something like this instead:

```log
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

## Step 4: Compile the program with a Cuda/HIP/SYCL backend

Recompile your program now using the Cuda backend, by instance.
You can use the following commands:

```sh
cmake -B build_cuda \
    -DKokkos_ENABLE_CUDA=ON \
    -DKokkos_ARCH_<ARCH>=ON
cmake --build build_cuda
```

Specify the architecture flag that applies.

If you have already installed Kokkos in exercise 0, then you can use the following commands instead:

```sh
cd exercise
cmake -B build_cuda \
    -DKokkos_ROOT=path/to/kokkos/cuda/install
cmake --build build_cuda
```

Run the program and check the output:

```sh
build_cuda/exe01
```

For instance if you are on Linux and are using GCC, you should get something like this on a computer with an A500 GPU:

```log
  Kokkos Version: 4.5.1
Compiler:
  KOKKOS_COMPILER_GNU: 1140
  KOKKOS_COMPILER_NVCC: 1220
Architecture:
  CPU architecture: none
  Default Device: Cuda
  GPU architecture: AMPERE86
  platform: 64bit
Atomics:
Vectorization:
  KOKKOS_ENABLE_PRAGMA_IVDEP: no
  KOKKOS_ENABLE_PRAGMA_LOOPCOUNT: no
  KOKKOS_ENABLE_PRAGMA_UNROLL: no
  KOKKOS_ENABLE_PRAGMA_VECTOR: no
Memory:
Options:
  KOKKOS_ENABLE_ASM: yes
  KOKKOS_ENABLE_CXX17: yes
  KOKKOS_ENABLE_CXX20: no
  KOKKOS_ENABLE_CXX23: no
  KOKKOS_ENABLE_CXX26: no
  KOKKOS_ENABLE_DEBUG_BOUNDS_CHECK: no
  KOKKOS_ENABLE_HWLOC: no
  KOKKOS_ENABLE_LIBDL: yes
Host Serial Execution Space:
  KOKKOS_ENABLE_SERIAL: yes

Serial Runtime Configuration:
Device Execution Space:
  KOKKOS_ENABLE_CUDA: yes
Cuda Options:
  KOKKOS_ENABLE_CUDA_RELOCATABLE_DEVICE_CODE: no
  KOKKOS_ENABLE_CUDA_UVM: no
  KOKKOS_ENABLE_IMPL_CUDA_MALLOC_ASYNC: no

Cuda Runtime Configuration:
macro  KOKKOS_ENABLE_CUDA      : defined
macro  CUDA_VERSION          = 12020 = version 12.2
Kokkos::Cuda[ 0 ] NVIDIA RTX A500 Laptop GPU capability 8.6, Total Global Memory: 3.813 GiB, Shared Memory per Block: 48 KiB : Selected
```
