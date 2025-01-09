# Contributing to the tutorials

## Add a new exercise

### Exercise structure

```
new_exercise/
+-- exercise/
|   +-- CMakeLists.txt
|   +-- main.cpp
+-- solution/
|   +-- CMakeLists.txt
|   +-- main.cpp
+-- CMakeLists.txt
+-- README.md
```

### Testing

Exercises should be tested in the CI.
To do so, edit `exercises/CMakeLists.txt` to append your exercise directory with `add_subdirectory`:

```cmake
add_subdirectory(my_exercise)
```

In your `solution/CMakeLists.txt`, add your solution target as a test.

```cmake
add_test(
    NAME my_exercise
    COMMAND my_exercise
)
```

The new exercise will be automatically built and tested by the CI.
