add_executable(tests test.cpp)

target_include_directories(tests PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(tests PUBLIC cube search)

add_test(NAME tests COMMAND tests)