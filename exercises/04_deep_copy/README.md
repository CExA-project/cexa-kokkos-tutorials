# Exercise 4: Mirror view and deep copy

## Objective

In this exercise, you will learn how to create a mirror view and how to use the `Kokkos::deep_copy` function to copy data between different execution spaces.

For this aim, we will create a mirror View of the existing View `matrix` and copy the data from the mirror View to the original View `matrix`.
Then, we will create a new mirror View `mirror_2` and copy the data from the original View `matrix` to the mirror View `mirror_2`.
The goal here is to move the data from the host to the device and back to the host in `mirror_2`.
Since at this stage, you do not know how to use the device, we use this second mirror View to ensure that the transfer were done correctly.
For this, we will simply compare the content of the two mirror Views located on the Host.

## Step 1: Create a a mirror view

We will start from the state of `main.cpp` of the previous exercise.

- Create a mirror View `mirror` of the existing View `matrix` using the `Kokkos::create_mirror_view` function.

**Reminder:** `Kokkos::create_mirror_view` creates a mirror View with the same properties as the original View. Does not duplicate the data if the View is on the same execution space.

- Get the extent and stride properties
- Print it in the terminal.
- Compile and run the program. Check the output and compare the View properties.

## Step 2: Initialize the mirror view

- Initialize the mirror View `mirror` with the values of your choice using imbricated loops:
    
```cpp
for (int i = 0; i < Nx; i++) {
    for (int j = 0; j < Ny; j++) {
        for (int k = 0; k < Nz; k++) {
            mirror(i, j, k) = ...
        }
    }
}
```

**Reminder:** Since the loops are classical C++, it will be executed on the Host.

## Step 3: Deep copy the mirror view

- Use the `Kokkos::deep_copy` function to copy the data from the mirror View to the original View `matrix`.

## Step 4: Bring back the data to the host

- Create a new mirror View called `mirror_2` using the `Kokkos::create_mirror` function.

**Reminder:** `Kokkos::create_mirror` creates a mirror View with the same properties as the original View but on the host. Always duplicated the data.

- Use the `Kokkos::deep_copy` function to copy the data from the original View `matrix` to the mirror View `mirror_2`.

## Step 5: Compute the error between the `mirror` and `mirror_2`

- Use imbricated loops to compute the error between the two Views, for instance:

```cpp
double error = 0.0;

for (int i = 0; i < Nx; i++) {
    for (int j = 0; j < Ny; j++) {
        for (int k = 0; k < Nz; k++) {
            error += std::abs(mirror(i, j, k) - mirror_2(i, j, k));
        }
    }
}
```

- Compile and run the program.

- Check that they contain the same data.

## step 6: Timers

The goal of this step is to measure the time of the deep copy operations. For this aim, you can use the `Kokkos::Timer` class or the C++ way.
The `Kokkos::Timer` class is very simple to use, see the example below:

```cpp
Kokkos::Timer timer;
// reset the timer
timer.reset();
// get the time in seconds since the last reset
std::cout << "Time: " << timer.seconds() << std::endl;
```

- Measure the time of the first and second deep copy operations.

- Print the time of the first and second deep copy operations.

- Compare and run the program using large sizes for `Nx`, `Ny`, and `Nz`.

- Compare the output of the time of the first and second deep copy operations. You can try different backends to see the difference.

**What should I get:**

If you are running the code using a CPU backend only, the View `matrix` is allocated on the Host. The mirror View `mirror` created with the `create_mirror_view` function is pointing toward the same data of `matrix`. However, the View `mirror_2` was created using the `create_mirror` function that implies a copy of the data from `matrix` to `mirror_2` (new allocation).
The  first `deep_copy` do not perform any deep copy since the data is the same.
The second `deep_copy` will however copy the data from `matrix` to `mirror_2`.
Although the error between `mirror` and `mirror_2` should be zero, the first `deep_copy` timer should be very short and the second `deep_copy` timer significantly higher than the first one.

Using a GPU backend, since the memory space is different, `matrix` is allocated on the Device memory while the mirrors live in the Host memory. Consequently, the first `deep_copy` will copy the data from the Host to the Device memory. The second `deep_copy` will copy the data from the Device to the Host. The error between `mirror` and `mirror_2` should be zero but the `deep_copy` timers relatively long (depending on the data size).