project(cube)

add_library(cube
        cube.cpp cube.h
)

target_include_directories(cube PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})