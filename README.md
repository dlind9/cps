# Build

Building is done using cmake, to build run

```
cmake .    # Makes the makefile
make       # Compiles the project
```

# Adding files

In the CMakeLists.txt file:

```
# Compiler Options
set(CMAKE_CXX_FLAGS "-O3 -Wall")
set (CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SOURCES
    shape.cpp
    circle.cpp
    models.cpp
    #### NEW CPP FILES GO HERE ####
)
add_executable(cps.out main.cpp ${SOURCES})

set(CATCH_INCLUDE_DIR tests)
set(TEST_SOURCES
    tests/test-main.cpp
    tests/test-circle.cpp
    #### NEW TESTING FILES GO HERE ####
)

```
