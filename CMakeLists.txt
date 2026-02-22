cmake_minimum_required(VERSION 3.24)

project(rubiks_solver)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-g -Wall -Wextra -pedantic)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BUILD_SHARED_LIBS ON)

# On Windows, create dll's in the same directory as the game executable
if (WIN32)
    set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
endif()

add_subdirectory(search)
add_subdirectory(cube)

add_executable(solver main.cpp)
target_link_libraries(solver PUBLIC cube search)
