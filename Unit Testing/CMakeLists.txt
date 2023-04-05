cmake_minimum_required(VERSION 3.0)
project(gymBuddi)

set(CMAKE_CXX_STANDARD 11)
set(OpenCV_DIR "../opencv_build")

find_package(OpenCV REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(GTest REQUIRED)

include_directories(../src)

enable_testing()

add_executable(test_run test_run.cpp)
target_link_libraries(test_run ${OpenCV_LIBS} Qt5::Widgets gtest gtest_main Camera CNNProcessor BlockingQueue PreProcessor)