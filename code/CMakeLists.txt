cmake_minimum_required(VERSION 3.10)
project(object)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Add include directories
include_directories(
    ${OpenCV_INCLUDE_DIRS}
    
add_subdirectory(model)

# Add source files
set(SOURCES
    main.cpp
)

target_link_libraries(tutorial ${OpenCV_LIBS} model)


add_executable(object main.cpp)
