/**
    @file camera_test.cpp
    @brief This includes a Unit test for the Camera class. 
*/

#include "Camera.h"
#include "MockPipelineLink.h"
#include "gtest/gtest.h"

/**
    @brief Test the start and stop functionality of the camera. This test creates a mock pipeline link, starts the camera thread, waits for the camera to capture a frame, stops the camera thread, and then verifies that the camera is off and that the pipeline link received at least one scene.
*/

TEST(CameraTest, StartStopTest) {

    MockPipelineLink mockPipelineLink;

    Camera camera;
    camera.setCallback(&mockPipelineLink);

    camera.Start();

    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    camera.Stop();

    EXPECT_FALSE(camera.getOn());
    EXPECT_GT(mockPipelineLink.getNumScenes(), 0);
}