/**
    @file cnnprocessor_test.cpp
    @brief This includes the unit tests for the CNNProcessor class
*/
#include <gtest/gtest.h>
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "CNNProcessor.h"
#include "Scene.h"
#include "CNNProcessorSettings.h"

/**
    @brief Test fixture for the CNNProcessor class
*/
class CNNProcessorTest : public ::testing::Test {
protected:

    /**
       @brief Constructor for CNNProcessorTest
    */

    CNNProcessorTest() : cnnProcessor(CNNProcessorSettings("model.pb", 224, 224)) { /*< Loads a sample image and creates a sample scene from the image >*/
        image = cv::imread("ProperForm.png");

        Scene s;
        s.frame = image;
        s.regionOfInterest = BoundingBox(0, 0, image.cols, image.rows);
        scene = s;
    }

    CNNProcessor cnnProcessor; /*< CNN processor object for testing >*/
    Scene scene; /*< Sample scene for testing >*/
    cv::Mat image; /*< Sample image for testing >*/
};

/**
    @brief Test to confirm if the CNNProcessor can process a scene and it checks that the result is a valid pose.
*/
TEST_F(CNNProcessorTest, ProcessScene) {
    Scene processedScene = cnnProcessor.ProcessScene(scene);

    EXPECT_GT(processedScene.result, gymBuddi::Pose::UNKNOWN);
    EXPECT_LT(processedScene.result, gymBuddi::Pose::NUM_POSES);
}

/**
    @brief Test to confirm that the CNNProcessor can make a blob from a scene and it checks that the resulting blob has the correct dimensions.
*/
TEST_F(CNNProcessorTest, MakeBlob) {
    cv::Mat blob = cnnProcessor.MakeBlob(scene);

    EXPECT_EQ(blob.size().width, cnnProcessor.settings.InputDim_x);
    EXPECT_EQ(blob.size().height, cnnProcessor.settings.InputDim_y);
}