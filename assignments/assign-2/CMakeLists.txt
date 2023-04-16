cmake_minimum_required(VERSION 3.16)

project(assign-2)

add_executable(assign-2
    main.cpp
    src/binarytree.cpp
    test/assign_test.cpp
)

target_include_directories(assign-2 PRIVATE
    include
)