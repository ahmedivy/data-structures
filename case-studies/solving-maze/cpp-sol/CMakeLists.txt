cmake_minimum_required(VERSION 3.16)

project(maze-solver)

add_executable(maze-solver
    src/direction.cpp
    src/location.cpp
    src/rat.cpp
    src/maze.cpp
    src/solvemaze.cpp
    main.cpp
)

add_executable(maze-solver-test
    src/direction.cpp
    src/location.cpp
    src/rat.cpp
    src/maze.cpp
    src/solvemaze.cpp
    test/testmaze.cpp
    test/testlocation.cpp
    test/test.cpp
)

target_include_directories(maze-solver
    PRIVATE include
)

target_include_directories(maze-solver-test
    PRIVATE include
)

add_custom_command(TARGET maze-solver POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${CMAKE_SOURCE_DIR}/puzzles $<TARGET_FILE_DIR:maze-solver>/puzzles
)
