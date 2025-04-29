cmake_minimum_required(VERSION 3.16)

# Project name and version
project(cli2048 VERSION 1.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(cli2048
    src/main.cpp
    src/game.cpp
    src/drawing.cpp
    src/input.cpp
)

# Include directories
target_include_directories(cli2048 PRIVATE src)

