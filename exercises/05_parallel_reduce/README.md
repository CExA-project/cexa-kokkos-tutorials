# Exercise 5: Parallel reduction

## Objective

The goal of this exercise is to use a Kokkos parallel reduction.

## Step 1: create a 2D matrix

Open the file `main.cpp` and create a 2D matrix of size `Nx` x `Ny` of type `double`.

Initialize the matrix with the values of your choice using `Kokkos::parallel_for` and `Kokkos::MDRangePolicy` with the default execution space.

## Step 2: compute the sum of the matrix

Use the `Kokkos::parallel_reduce` to compute the sum of the matrix and add the code to print the result.

## Step 3: compute the maximum of the matrix

Use `Kokkos::parallel_reduce`  and the reducer `Kokkos::Max` to compute the max element and add the code to print the result.

## Step 4: timers

Add timers to measure the time spent to compute the sum and the max of the matrix.

## Step 5: compile and run the program

Compile the program using the OpenMP backend and run it.
Check the output and the timings.

If you have access to a GPU, compile the program using a GPU backend and run it.
Check the output and compare them with the OpenMP backend.
