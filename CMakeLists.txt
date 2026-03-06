cmake_minimum_required(VERSION 3.24)

project(rubiks_solver)

set(CMAKE_CXX_STANDARD 20)
add_compile_options(-g -Wall -Wextra -pedantic -Ofast)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(BUILD_SHARED_LIBS ON)

add_subdirectory(search)
add_subdirectory(cube)

add_executable(solver main.cpp)
target_link_libraries(solver PUBLIC cube search)
