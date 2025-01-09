# Exercise 2: How to use and manage Kokkos Views

In this exercise, you will learn how to use and manage basic Kokkos Views.

## Step 1: Create a Kokkos View

Open the file `main.cpp` that will be used for this exercise.
Create a 3D Kokkos View of size `Nx` x `Ny` x `Nz` of type `double`:

```cpp
Kokkos::View<double***> matrix("matrix", Nx, Ny, Nz);
```

## Step 2: Get the rank of the View

Call the `rank` method to get the number of dimensions of the View and store it in a variable `rank`.
Add the code to print it in the terminal, for instance:

```cpp
std::cout << "Matrix rank: " << rank << std::endl;
```

## Step 3: Get the extent of the View

Call the `extent` method to get the size of each dimension of the View
Add the code to print it in the terminal.

## Step 4: Layout of the View

Call the `stride` method to get the stride of each dimension of the View
Add the code to print it in the terminal.

## Step 5: Compile and run the program

Compile the program using the OpenMP backend and run it.
Check the output.

Deduce from the stride the layout of the View.

If you have access to a GPU, compile the program using a GPU backend and run it.
Check the output and compare them with the OpenMP backend.
