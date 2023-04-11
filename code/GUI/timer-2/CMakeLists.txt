cmake_minimum_required(VERSION 3.7.0)

project(opencv-camera-calback VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)
find_package(Threads REQUIRED)
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )

add_executable(test
  CountUpTimer.cpp
  TimerControls.cpp
  #mainwindow.cpp
  main.cpp
)

target_link_libraries(test Qt5::Widgets)
target_link_libraries(test qwt-qt5)
target_link_libraries(test ${OpenCV_LIBS} Threads::Threads)

install(TARGETS test)
