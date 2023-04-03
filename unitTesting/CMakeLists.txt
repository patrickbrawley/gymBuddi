cmake_minimum_required(VERSION 3.10)
project(gymBuddi)

find_package(OpenCV REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
set(CMAKE_CXX_STANDARD 11)

# Set up the sources and headers for the CNN processor.
set(CNN_PROCESSOR_SOURCES CNNProcessor.cpp)
set(CNN_PROCESSOR_HEADERS CNNProcessor.h)

# Set up the sources and headers for the link splitter.
set(LINK_SPLITTER_SOURCES LinkSplitter.cpp)
set(LINK_SPLITTER_HEADERS LinkSplitter.h)

# Set up the sources and headers for the pre-processor.
set(PRE_PROCESSOR_SOURCES PreProcessor.cpp)
set(PRE_PROCESSOR_HEADERS PreProcessor.h)

# Set up the sources and headers for the scene pipeline link.
set(PIPELINE_LINK_SOURCES PipelineLink.cpp)
set(PIPELINE_LINK_HEADERS PipelineLink.h)

# Set up the sources and headers for the camera.
set(CAMERA_SOURCES Camera.cpp)
set(CAMERA_HEADERS Camera.h)

# Set up the sources and headers for the count-up timer.
set(TIMER_SOURCES CountUpTimerTest.cpp)
set(TIMER_HEADERS CountUpTimer.h)

# Set up the sources and headers for the scene.
set(SCENE_HEADERS Scene.h)

# Set up the sources and headers for the unit tests.
set(UNIT_TEST_SOURCES
    CNNProcessor_test.cpp
    LinkSplitter_test.cpp
    PreProcessor_test.cpp
    PipelineLink_test.cpp
    test_camera.cpp
    CountUpTimerTest.cpp
    Scene_test.cpp   
)

set(UNIT_TEST_HEADERS)

# Create the library targets for the sources and headers.
add_library(cnn_processor ${CNN_PROCESSOR_SOURCES} ${CNN_PROCESSOR_HEADERS})
add_library(link_splitter ${LINK_SPLITTER_SOURCES} ${LINK_SPLITTER_HEADERS})
add_library(pre_processor ${PRE_PROCESSOR_SOURCES} ${PRE_PROCESSOR_HEADERS})
add_library(pipeline_link ${PIPELINE_LINK_SOURCES} ${PIPELINE_LINK_HEADERS})
add_library(camera ${CAMERA_SOURCES} ${CAMERA_HEADERS})
add_library(timer ${TIMER_SOURCES} ${TIMER_HEADERS})
add_library(scene ${SCENE_HEADERS})

# Create the executable targets for the unit tests.
add_executable(cnn_processor_test CNNProcessor_test.cpp)
add_executable(link_splitter_test LinkSplitter_test.cpp)
add_executable(pre_processor_test PreProcessor_test.cpp)
add_executable(pipeline_link_test PipelineLink_test.cpp)
add_executable(camera_test test_camera.cpp)
add_executable(timer_test CountUpTimerTest.cpp)
add_executable(scene_test Scene_test.cpp)

# Link the libraries and Google Test to the unit test executables.
target_link_libraries(cnn_processor_test cnn_processor ${GTEST_LIBRARIES})
target_link_libraries(link_splitter_test link_splitter ${GTEST_LIBRARIES})
target_link_libraries(pre_processor_test pre_processor ${GTEST_LIBRARIES})
target_link_libraries(pipeline_link_test pipeline_link ${GTEST_LIBRARIES})
target_link_libraries(camera_test camera ${GTEST_LIBRARIES})
target_link_libraries(timer_test timer ${GTEST_LIBRARIES})
target_link_libraries(scene_test scene ${GTEST_LIBRARIES})

# Add the test targets for CTest.
enable_testing()
add_test(cnn_processor_test cnn_processor_test)
add_test(link_splitter_test link_splitter_test)
add_test(pre_processor_test pre_processor_test)
add_test(pipeline_link_test pipeline_link_test)
add_test(camera_test camera_test)
add_test(timer_test timer_test)
add_test(scene_test scene_test)