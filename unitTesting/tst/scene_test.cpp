#include "Scene.h"
#include <opencv2/highgui/highgui.hpp>
#include <gtest/gtest.h>

TEST(SceneTest, ConstructorTest){
    Scene scene;
    EXPECT_EQ(scene.result, "");
    EXPECT_EQ(scene.regionOfInterest.UpperLeft.x, 0);
    EXPECT_EQ(scene.regionOfInterest.UpperLeft.y, 0);
    EXPECT_EQ(scene.regionOfInterest.LowerRight.x, 0);
    EXPECT_EQ(scene.regionOfInterest.LowerRight.y, 0);
}

TEST(SceneTest, FrameTest){
    Scene scene;
    cv::Mat testMat(5,5,CV_8UC1,cv::Scalar(255));
    scene.frame = testMat;
    EXPECT_EQ(scene.frame.size().width, 5);
    EXPECT_EQ(scene.frame.size().height, 5);
    EXPECT_EQ(scene.frame.type(), CV_8UC1);
}

TEST(SceneTest, BoundingBoxTest){
    BoundingBox boundingBox(10,10,20,20);
    EXPECT_EQ(boundingBox.UpperLeft.x, 10);
    EXPECT_EQ(boundingBox.UpperLeft.y, 10);
    EXPECT_EQ(boundingBox.LowerRight.x, 20);
    EXPECT_EQ(boundingBox.LowerRight.y, 20);
    Point upperLeft(5,5);
    Point lowerRight(15,15);
    boundingBox = BoundingBox(upperLeft, lowerRight);
    EXPECT_EQ(boundingBox.UpperLeft.x, 5);
    EXPECT_EQ(boundingBox.UpperLeft.y, 5);
    EXPECT_EQ(boundingBox.LowerRight.x, 15);
    EXPECT_EQ(boundingBox.LowerRight.y, 15);
}
