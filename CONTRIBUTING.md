# Contributing to the tutorials

## Add a new exercise or a new project

### Directory structure

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

Exercises and projects should be tested in the CI.
To do so, edit `exercises/CMakeLists.txt` or `projects/CMakeLists.txt` to append your exercise directory with `add_subdirectory`:

```cmake
add_subdirectory(my_exercise)
```

In your `solution/CMakeLists.txt` (or any build you want to test), add your solution target as a test.

```cmake
add_test(
    NAME my_exercise
    COMMAND my_exercise
)
```

You can customise the `COMMAND` with any extra arguments for the test.

The new exercise will be automatically built and tested by the CI.
