cmake_minimum_required(VERSION 3.16)

project(capital-gains)

add_executable(capital-gains
    src/date.cpp
    main.cpp
)

target_include_directories(capital-gains
    PRIVATE
        include
)
