cmake_minimum_required(VERSION 3.7.0)

project(qwt-example-app VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(qwt-example1
  window.cpp
  main.cpp
)

target_link_libraries(qwt-example1 Qt5::Widgets)
target_link_libraries(qwt-example1 qwt-qt5)

install(TARGETS qwt-example1)
