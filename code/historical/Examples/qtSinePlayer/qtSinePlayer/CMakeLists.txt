cmake_minimum_required(VERSION 3.7.0)

project(Audiobeep VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets Multimedia REQUIRED)

add_executable(qtsineplay
  audiobeep.cpp
  window.cpp
  main.cpp
)

target_link_libraries(qtsineplay Qt5::Widgets)
target_link_libraries(qtsineplay Qt5::Multimedia)

install(TARGETS qtsineplay)
