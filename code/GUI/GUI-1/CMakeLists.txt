cmake_minimum_required(VERSION 3.7.0)

project(gymbuddi VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(QT5 COMPONENTS Widgets REQUIRED)

add_executable(GUI-1
    main.cpp
)

target_link_libraries(GUI-1 QT5::Widgets)
target_link_libraries(GUI-1 qwt-qt5)

install(TARGETS GUI-1)