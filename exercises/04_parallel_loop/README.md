# Exercise 4: My first Parallel loop

## Objective

The goal of this exercise is to use a Kokkos parallel loop.

## Steps 1: create a View

In the file `main.cpp`, create a 1D View of size `N` and type `double`.

## Step 2: parallel loop

Use the `Kokkos::parallel_for` function to initialize the View with the values of your choice on the Device.

Add the `Kokkos::fence()` function after the parallel for.

## Step 3: get the data back to the host

Create a mirror View called `mirror` using the `Kokkos::create_mirror_view` function.

Use the `Kokkos::deep_copy` function to copy the data from the original View to the mirror View.

## Step 4: check the result

Use a loop to check that the data is correct by computing the error between the `mirror` View and the expected result.

## Step 5: timers

Add timers to measure the time spent in the parallel loop and the time spent to copy the data back to the host.

## Step 6: compile and run the program

Prepare the OpenMP environment:

```sh
export OMP_NUM_THREADS=<the number of cores you want to use>
export OMP_PROC_BIND=spread
export OMP_PLACES=threads
```

Compile the program with the OpenMP backend and execute.
Use a large View size for more meaningful results:

```sh
build_openmp/exe04 10000000
```

If you have access to a GPU, compile and execute the program with the corresponding backend and execute the code.
Compare the times between the two backends.
