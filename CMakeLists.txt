# Specify the minimum CMake version
cmake_minimum_required(VERSION 3.16)

# Set the project name
project(SDLGAME)

# Enable compile_commands.json generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Find the SDL2 library
find_package(SDL2 REQUIRED)

# Add the source files
add_executable(main src/main.c)

# Include the SDL2 headers
include_directories(${SDL2_INCLUDE_DIRS})

# Link the SDL2 library
target_link_libraries(main ${SDL2_LIBRARIES})
