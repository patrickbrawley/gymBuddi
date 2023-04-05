#include "Camera.h"
#include "MockPipelineLink.h"
#include "gtest/gtest.h"

TEST(CameraTest, StartStopTest) {
    // Create a mock pipeline link
    MockPipelineLink mockPipelineLink;

    // Create a camera with default settings
    Camera camera;
    camera.setCallback(&mockPipelineLink);

    // Start the camera thread
    camera.Start();

    // Wait for the camera to capture a frame
    std::this_thread::sleep_for(std::chrono::milliseconds(500));

    // Stop the camera thread
    camera.Stop();

    // Ensure that the camera is off
    EXPECT_FALSE(camera.getOn());

    // Ensure that the pipeline link received at least one scene
    EXPECT_GT(mockPipelineLink.getNumScenes(), 0);
}