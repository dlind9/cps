cmake_minimum_required(VERSION 2.8.9)
project(CheckersAi)

# Compiler Options
set(CMAKE_CXX_FLAGS "-O3 -Wall")
set (CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

#Can manually add the sources using the set command as follows:
set(SOURCES
    shape.cpp
    circle.cpp
    models.cpp
)
add_executable(cps.out main.cpp ${SOURCES})

set(CATCH_INCLUDE_DIR tests)
set(TEST_SOURCES
    tests/test-main.cpp
    tests/test-circle.cpp
)

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

add_executable(test.out ${TEST_SOURCES} ${SOURCES})
target_link_libraries(test.out Catch)

enable_testing()
add_test(NAME MyAwesomeTest COMMAND test.out)
