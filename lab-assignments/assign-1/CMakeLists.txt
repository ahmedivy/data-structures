cmake_minimum_required(VERSION 3.16)

add_executable(assign-1
    main.cpp
)

target_include_directories(maze-solver
    PRIVATE include
)