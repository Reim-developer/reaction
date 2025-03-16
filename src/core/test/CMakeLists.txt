cmake_minimum_required(VERSION 3.10)
project(test_reaction)

set(SOURCE
    test.c
    ../format.c
)
add_executable(test ${SOURCE})
target_include_directories(test PRIVATE ../)