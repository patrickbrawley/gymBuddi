cmake_minimum_required(VERSION 3.10)
project(Camera)

find_package(OpenCV REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 11)

set(OpenCV_DIR "../opencv_build")

include_directories(../src)

enable_testing()


add_executable(runTests test_camera.h)
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)


file(GLOB_RECURSE SOURCES LIST_DIRECTORIES true *.h *.cpp)