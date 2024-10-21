# Exercise 5: Parallel Loop

## Objective

The goal of this exercise is to manipulate the Kokkos parallel reduction.

## Step 1: create a 2D matrix

- Open the file `main.cpp`
- Create a 2D matrix of size `Nx` x `Ny` of type `double`
- Initialize the matrix with the values of your choice using `Kokkos::parallel_for` and `Kokkos::MDRangePolicy` with the default execution space

## Step 2: compute the sum of the matrix

- Use the `Kokkos::parallel_reduce` to compute the sum of the matrix
- Add the code to print the result

## Step 3: compute the maximum of the matrix

- Use `Kokkos::parallel_reduce`  and the reducer `Kokkos::Max` to compute the max element
- Add the code to print the result

## Step 4: compile and run the program

- Compile the program using the OpenMP backend and run it. Check the output.
- If you can access a GPU, compile the program using a GPU backend and run it. Check the output and compare them with the OpenMP backend.

## *Optional* Step: timers

- Add timers to measure the time spent to compute the sum and the max of the matrix.
- Analyze the time spent on CPU and GPU for different LMatrix sizes.