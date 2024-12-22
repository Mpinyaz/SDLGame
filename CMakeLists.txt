# Specify the minimum CMake version
cmake_minimum_required(VERSION 3.16)

# Set the project name
project(SDLGAME)

# Enable compile_commands.json generation
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Set C standard
set(CMAKE_C_STANDARD 11)

# Find the SDL2 and OpenGL libraries
find_package(SDL2 REQUIRED)
find_package(Vulkan REQUIRED)

# Add the source files
add_executable(sdl_app src/main.c)

# Include the SDL2 and OpenGL headers
include_directories(${SDL2_INCLUDE_DIRS} ${Vulkan_INCLUDE_DIRS})

# Link the SDL2 and OpenGL libraries
target_link_libraries(sdl_app ${SDL2_LIBRARIES} ${Vulkan_LIBRARIES})
