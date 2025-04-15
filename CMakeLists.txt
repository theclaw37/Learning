cmake_minimum_required(VERSION 3.10)

# Set the project name
project(Learning)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Set the build type to Debug
set(CMAKE_BUILD_TYPE Debug)

# Specify the build folder
set(BUILD_FOLDER "${CMAKE_BINARY_DIR}/bin")

# Create the build folder if it doesn't exist
file(MAKE_DIRECTORY ${BUILD_FOLDER})

# Optionally, set the output directories for binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BUILD_FOLDER})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${BUILD_FOLDER})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${BUILD_FOLDER})

# Include the SFML library
set(SFML_PATH "/opt/homebrew/Cellar/sfml/3.0.0_1")
include_directories(${SFML_PATH}/include)
link_directories(${SFML_PATH}/lib)

# Add compiler flags to enable all warnings
add_compile_options(-Wall)

# Add compiler flags to enable colorized output
add_compile_options(-fdiagnostics-color=always)

# Add the executable
add_executable(Learning main.cpp)
set_target_properties(Learning PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${BUILD_FOLDER})

# Link the SFML libraries
# target_link_libraries(Learning sfml-graphics sfml-window sfml-system)