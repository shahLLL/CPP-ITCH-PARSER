cmake_minimum_required(VERSION 3.12)
project(lob LANGUAGES CXX)

# Require C++23
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT MSVC)
    add_compile_options(-O3 -march=native)
endif()

# Collect all C++ files in the src/ directory
file(GLOB SOURCES "src/*.cpp")

# Define the executable target
add_executable(itchparse main.cpp ${SOURCES})

# Apply compiler warning flags
target_compile_options(itchparse PRIVATE -Wall -Wextra)