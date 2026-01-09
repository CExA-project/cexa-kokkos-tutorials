# Exercise 11: Correct race condition using atomics

## Objective

The goal of this exercise is to profile an existing Kokkos program which solves the heat equation.

## Step 1:

Compile the exercice program using a parallel backend (Cuda/HIP/OpenMP/...).

Check that the result of the parallel operation differ with each execution.

## Step 2: use atomic operations to correct the race condition

Use an atomic operation to correct the race condition.
