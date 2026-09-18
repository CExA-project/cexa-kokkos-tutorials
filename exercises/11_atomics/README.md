# Exercise 11: Correct race condition using atomics

## Objective

The goal of this exercice is to experiment with race conditions and learn how to solve them using atomics.

## Step 1: observe the absence of a race condition in serial execution context

Compile the exercice program using NO parallel backend (KOKKOS_ENABLE_SERIAL=ON should be the only backend option).
Execute the program several time and observe that the result is the same each time.

## Step 2: observe the race condition

Compile the exercice program using a parallel backend (Cuda/HIP/OpenMP/...).
Execute the program several time and observe that the result of the parallel operation changes randomly.

## Step 3: Experiment with atomic operation

Replace the operation in the kernel with an atomic operation.
Check that it solved the race condition.

## Step 4: Experiment with memory traits

Reset the code to step 2 (remove the atomic operation) and create an alias for the `histo` view with the correct memory trait.
Check that it solved the race condition.
