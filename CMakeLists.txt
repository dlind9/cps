cmake_minimum_required(VERSION 2.8.9)
project(CheckersAi)

# Compiler Options
set(CMAKE_CXX_FLAGS "-O3 -Wall")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(headers)

#Can manually add the sources using the set command as follows:
set(SOURCES
    headers/rectangle.h
    headers/shape.h
    headers/circle.h
    headers/models.h
    headers/polygon.h
    headers/triangle.h
    source/rectangle.cpp
    source/polygon.cpp
    source/shape.cpp
    source/circle.cpp
    source/models.cpp
    source/triangle.cpp
)
add_executable(cps.out source/main.cpp ${SOURCES})

set(CATCH_INCLUDE_DIR tests)
set(TEST_SOURCES
    tests/test-circle.cpp
    tests/test-main.cpp
    tests/test-polygon.cpp
    tests/test-rectangle.cpp
    tests/test-shape.cpp
    tests/test-triangle.cpp
    tests/test-translation.cpp
)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

add_executable(test.out ${TEST_SOURCES} ${SOURCES})
target_link_libraries(test.out Catch)

enable_testing()
add_test(NAME MyAwesomeTest COMMAND test.out)
