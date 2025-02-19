cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Learning)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the build type to Debug
set(CMAKE_BUILD_TYPE Debug)

# Add the executable
add_executable(Learning main.cpp problem4.cpp)