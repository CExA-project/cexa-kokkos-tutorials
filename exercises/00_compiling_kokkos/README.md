# Exercise 0: Compiling Kokkos

> [!NOTE]
> This exercise is optional.

In this exercise, you will learn how to compile Kokkos from source.
This is a necessary step if you want to use Kokkos on a system where it is not already installed.

## Step 1: Get the Kokkos repository

You can either clone the Kokkos repository, download a release archive, or use the submodule included in this current repository.

### Clone the Kokkos repository

Use the following command to clone the repository into a directory called `kokkos` and use the latest release.

```sh
git clone git@github.com:kokkos/kokkos.git --branch 4.5.01
```

### Download a release archive

Alternatively, you can download the source code from the release page on GitHub [here](https://github.com/kokkos/kokkos/releases).

```sh
wget https://github.com/kokkos/kokkos/archive/refs/tags/4.5.01.tar.gz
tar xvf 4.5.01.tar.gz
mv kokkos-4.5.01 kokkos
```

### Use the submodule

The `../../../vendor/kokkos` directory contains Kokkos as a Git submodule.
If you haven't cloned the repository recursively already, you can get it with:

```sh
git submodule update --init
```

Then you create a link here:

```sh
ln -s ../../../vendor/kokkos kokkos
```

## Step 2: Build Kokkos with default parameters

We recommend to build Kokkos in a separate directory (compulsory) and create as well a specific folders for installation artifacts.
This way, you can easily clean up the build directory without affecting the source code.

To create a build directory and build Kokkos with default parameters, you can use the following commands:

```bash
cmake -B build_serial -DCMAKE_INSTALL_PREFIX=${PWD}/install_serial kokkos
cmake --build build_serial
cmake --install build_serial
```

Check that the serial backend (enabled by default) is correctly compiled.

## Step 3: Build Kokkos with the OpenMP backend

Make sure your compiler supports OpenMP.

To build Kokkos with the OpenMP backend, you can use the following commands:

```bash
cmake -B build_openmp -DCMAKE_INSTALL_PREFIX=${PWD}/install_openmp -DKokkos_ENABLE_OPENMP=ON kokkos
cmake --build build_openmp
cmake --install build_openmp
```

> [!NOTE]
> Apple clang does not have OpenMP installed by default.
> You can install GNU GCC or LLVM with OpenMP support using Homebrew.
> Then specify the compiler using `-DCMAKE_CXX_COMPILER=g++`.
> Alternatively, Mac users can use the `THREADS` backend.

## Step 4: Build Kokkos with the Cuda/HIP/SYCL backend

If you have a GPU and the related toolchain installed, you can build Kokkos with a device backend (i.e., Cuda, HIP, or SYCL).

Try compiling Kokkos with an OpenMP backend and a device backend.
For instance for CUDA, use the following commands:

```bash
cmake -B build_cuda -DCMAKE_INSTALL_PREFIX=${PWD}/install_cuda -DKokkos_ENABLE_CUDA=ON kokkos
cmake --build build_cuda
cmake --install build_cuda
```
