cmake_minimum_required(VERSION 3.16)

project(capital-gains)

add_executable(capital-gains
    src/date.cpp
    src/transaction.cpp
    main.cpp
)

target_include_directories(capital-gains
    PRIVATE
        include
)

# Copy data folder to build directory
file(COPY ${CMAKE_SOURCE_DIR}/data DESTINATION ${CMAKE_BINARY_DIR})
