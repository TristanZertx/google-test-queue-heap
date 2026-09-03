cmake_minimum_required(VERSION 3.10)
project(QueueHeapTests)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Include directories
include_directories(${PROJECT_SOURCE_DIR}/include)

# Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/release-1.12.1.zip
)
FetchContent_MakeAvailable(googletest)

# Queue Tests
add_executable(queue_test tests/queue_test.cpp)
target_link_libraries(queue_test gtest gtest_main)

# Heap Tests
add_executable(heap_test tests/heap_test.cpp)
target_link_libraries(heap_test gtest gtest_main)

# Enable testing
enable_testing()
add_test(NAME QueueTests COMMAND queue_test)
add_test(NAME HeapTests COMMAND heap_test)
