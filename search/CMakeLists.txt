project(search)

add_library(search
        node.cpp node.h
        problem.cpp problem.h
)

target_include_directories(search PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})