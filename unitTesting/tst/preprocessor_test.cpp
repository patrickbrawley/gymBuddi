/**
    @file preprocessor_test.cpp
    @brief This includes the unit test for the PreProcessor class.
*/
#include <gtest/gtest.h>
#include <opencv2/core.hpp>
#include "Scene.h"
#include "PipelineLink.h"
#include "PreProcessorSettings.h"
#include "PreProcessor.h"

/**
    @brief Test the ProcessScene method of the PreProcessor class.
*/
TEST(PreProcessorTest, ProcessSceneTest) {
    cv::Mat inputImg(100, 100, CV_8UC3, cv::Scalar(255, 255, 255)); /*< Create a sample input scene >*/
    Scene inputScene(inputImg);

    PreProcessorSettings defaultSettings; /*< Set up the PreProcessor with default settings >*/
    PreProcessor preProcessor(defaultSettings);

    preProcessor.SetBoundingBox(0.0, 0.0, 1.0, 1.0); /*< Set the bounding box to cover the entire input scene >*/

    Scene processedScene = preProcessor.NextScene(inputScene); /*< Call the NextScene method with the input scene >*/

    cv::Mat outputImg = processedScene.frame; /*< Verify that the output scene has a green rectangle drawn on it >*/
    cv::Scalar color = cv::Scalar(0, 255, 0);
    cv::Rect bbox = cv::Rect(0, 0, 100, 100);
    cv::rectangle(outputImg, bbox, color);
    bool hasGreenRectangle = cv::countNonZero(outputImg == color * cv::Mat::ones(outputImg.size(), outputImg.type())) == outputImg.total();

    ASSERT_TRUE(hasGreenRectangle);
}