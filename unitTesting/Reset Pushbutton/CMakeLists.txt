cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(CountUpTimerTest VERSION 1.0)

# Add the Google Test library
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add the source files
set(SOURCES
    CountUpTimerTest.cpp
    CountUpTimer.h
)

# Create the executable
add_executable(test_timer ${SOURCES})

# Link the executable with the Google Test library
target_link_libraries(test_timer ${GTEST_LIBRARIES} pthread)

# Add a test to the project
add_test(NAME Count-up Timer COMMAND CountUpTimerTest)