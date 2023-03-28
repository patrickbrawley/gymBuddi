cmake_minimum_required(VERSION 3.10)
project(GUI-1)

set(CMAKE_CXX_STANDARD 11)

enable_testing()

include_directories(src)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)