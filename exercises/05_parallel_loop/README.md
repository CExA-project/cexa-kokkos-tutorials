# Exercise 5: Parallel Loop

## Objective

The goal of this exercise is to manipulate the Kokkos parallel loop.

## Steps 1: create a vector

- Open the file `main.cpp`

- Create a vector of size `N` of type `double`

# Step 2: parallel loop

- Use the `Kokkos::parallel_for` to initialize the vector with the values of your choice on Device.

- Add the `Kokkos::fence()` function after the parallel loop.

# Step 3: get the data back to the host

- Create a mirror View called `mirror` using the `Kokkos::create_mirror_view` function.

- Use the `Kokkos::deep_copy` function to copy the data from the original View to the mirror View.

# Step 4: check the result

- Use a loop to check that the data is correct by computing the error between the `mirror` View and the expected result.

# Step 5: timers

- Add timers to measure the time spent in the parallel loop and the time spent to copy the data back to the host.

# Step 6: compile and run the program

- Prepare the OpenMP environment:

```bash
export OMP_NUM_THREADS=<the number of cores you want to use>
export OMP_PROC_BIND=spread
export OMP_PLACES=threads
```

- Compile the program with the OpenMP backend and execute. Use large vector size for better results:

```bash
./exe -N 10000000
```

- If you can access a GPU, compile and execute the program with the corresponding backend and execute the code.

- Compare the timers between the two backends.