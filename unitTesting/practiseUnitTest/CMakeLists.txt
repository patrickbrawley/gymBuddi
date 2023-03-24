cmake_minimum_required(VERSION 3.10)
project(practiseUnitTest)

set(CMAKE_CXX_STANDARD 14)

include_directories(src)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)

add_subdirectory(src)
add_subdirectory(tst)
add_subdirectory(lib/googletest)

