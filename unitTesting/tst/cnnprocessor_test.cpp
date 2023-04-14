#include <gtest/gtest.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "CNNProcessor.h"
#include "Scene.h"
#include "CNNProcessorSettings.h"

// Test fixture for CNNProcessor class
class CNNProcessorTest : public ::testing::Test {
protected:
    CNNProcessorTest() : cnnProcessor(CNNProcessorSettings("model.pb", 224, 224)) {
        // Load sample image
        image = cv::imread("test_image.jpg");

        // Create a sample scene from the image
        Scene s;
        s.frame = image;
        s.regionOfInterest = BoundingBox(0, 0, image.cols, image.rows);
        scene = s;
    }

    CNNProcessor cnnProcessor;
    Scene scene;
    cv::Mat image;
};

// Test that the CNNProcessor can process a scene
TEST_F(CNNProcessorTest, ProcessScene) {
    Scene processedScene = cnnProcessor.ProcessScene(scene);

    // Check that the result is a valid pose
    EXPECT_GT(processedScene.result, gymBuddi::Pose::UNKNOWN);
    EXPECT_LT(processedScene.result, gymBuddi::Pose::NUM_POSES);
}

// Test that the CNNProcessor can make a blob from a scene
TEST_F(CNNProcessorTest, MakeBlob) {
    cv::Mat blob = cnnProcessor.MakeBlob(scene);

    // Check that the blob has the correct dimensions
    EXPECT_EQ(blob.size().width, cnnProcessor.settings.InputDim_x);
    EXPECT_EQ(blob.size().height, cnnProcessor.settings.InputDim_y);
}