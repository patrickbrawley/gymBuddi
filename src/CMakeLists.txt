cmake_minimum_required(VERSION 3.10)
project(myproject)

# Find OpenCV package
find_package(OpenCV REQUIRED)

# Add include directories
include_directories(
    ${OpenCV_INCLUDE_DIRS}
)

# Add source files
set(SOURCES
    picamera.cpp
    main.cpp
)

# Create executable
add_executable(myprogram ${SOURCES})

# Link libraries
target_link_libraries(myprogram pthread)
target_link_libraries(myprogram
    ${OpenCV_LIBS}
)
