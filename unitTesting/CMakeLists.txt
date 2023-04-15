set(BINARY ${CMAKE_PROJECT_NAME}_tst)
set(SOURCES ${TEST_SOURCES})

cmake_minimum_required(VERSION 3.0)
project(GymBuddi)

set(CMAKE_CXX_STANDARD 11)

find_package(OpenCV REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5 COMPONENTS Core REQUIRED)
find_package(GTest REQUIRED)

include_directories(../src)

add_subdirectory(tst)
add_subdirectory(lib/googletest)

file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)








