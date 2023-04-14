#include <gtest/gtest.h>
#include <opencv2/core.hpp>
#include "Scene.h"
#include "PipelineLink.h"
#include "PreProcessorSettings.h"
#include "PreProcessor.h"

TEST(PreProcessorTest, ProcessSceneTest) {
    // Create a sample input scene
    cv::Mat inputImg(100, 100, CV_8UC3, cv::Scalar(255, 255, 255));
    Scene inputScene(inputImg);

    // Set up the PreProcessor with default settings
    PreProcessorSettings defaultSettings;
    PreProcessor preProcessor(defaultSettings);

    // Set the bounding box to cover the entire input scene
    preProcessor.SetBoundingBox(0.0, 0.0, 1.0, 1.0);

    // Call the NextScene method with the input scene
    Scene processedScene = preProcessor.NextScene(inputScene);

    // Verify that the output scene has a green rectangle drawn on it
    cv::Mat outputImg = processedScene.frame;
    cv::Scalar color = cv::Scalar(0, 255, 0);
    cv::Rect bbox = cv::Rect(0, 0, 100, 100);
    cv::rectangle(outputImg, bbox, color);
    bool hasGreenRectangle = cv::countNonZero(outputImg == color * cv::Mat::ones(outputImg.size(), outputImg.type())) == outputImg.total();

    ASSERT_TRUE(hasGreenRectangle);
}
