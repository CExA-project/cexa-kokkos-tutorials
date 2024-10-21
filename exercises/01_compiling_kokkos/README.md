# Exercise 1: Compiling Kokkos

In this exercise, you will learn how to compile Kokkos from source. This is a necessary step if you want to use Kokkos on a system where it is not already installed.

## Step 1: Get the Kokkos repository

You can use git to clone the Kokkos repository. The following command will clone the repository into a directory called `kokkos` and use the latest release.

```bash
git clone git@github.com:kokkos/kokkos.git --branch release-candidate-4.4.00
```

Alternatively, you can download the source code from the release page on GitHub. You can find the release page [here](https://github.com/kokkos/kokkos/releases).

**Note:** The `release-candidate-4.4.00` branch is the latest release candidate at the time of writing. You can find the latest release candidate by visiting the [Kokkos GitHub page](https://github.com/kokkos/kokkos).

## Step 2: Build Kokkos with default parameters

We recommend to build Kokkos in a separate directory (compulsory) and create as well a specific folders for installation artifacts.
This way, you can easily clean up the build directory without affecting the source code.

- To create a build directory and build Kokkos with default parameters, you can use the following commands:

```bash
mkdir build
mkdir install
cmake -B build  -DCMAKE_INSTALL_PREFIX=${PWD}/install ./
make -C build
make install -C build
```

- Check that the serial backend is correctly compiled

## Step 3: Build Kokkos with the OpenMP backend

Make sure your compiler comes with OpenMP.

- To build Kokkos with the OpenMP backend, you can use the following commands:

```bash
mkdir build_openmp
mkdir install_openmp
cmake -B build_openmp -DCMAKE_INSTALL_PREFIX=${PWD}/install_openmp -DKokkos_ENABLE_OPENMP=ON ./
make install -C build_openmp
```

**Note:** Apple clang does not have OpenMP installed by default. You can install GNU GCC or LLVM with OpenMP support using Homebrew. Then specify the compiler using `CMAKE_CXX_COMPILER`.
**Note:** Alternatively, Mac users can use the `THREADS` backend.

## Step 4: Build Kokkos with a device backend

If you have a GPU and the related toolchain installed, you can build Kokkos with a device backend.

- Try compiling Kokkos with an OpenMP backend and a device backend. For instance for CUDA:

```bash
mkdir build_cuda
mkdir install_cuda
cmake -B build_cuda -DCMAKE_INSTALL_PREFIX=${PWD}/install_cuda -DKokkos_ENABLE_CUDA=ON -DKokkos_ENABLE_OPENMP=ON ./
make -C build_cuda
make install -C build_cuda
```