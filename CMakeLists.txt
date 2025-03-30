cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Learning)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the build type to Debug
set(CMAKE_BUILD_TYPE Debug)

# Include the SFML library
set(SFML_PATH "/opt/homebrew/Cellar/sfml/3.0.0_1")
include_directories(${SFML_PATH}/include)
link_directories(${SFML_PATH}/lib)

# Add compiler flags to enable all warnings
add_compile_options(-Wall)

# Add the executable
add_executable(Learning main.cpp)