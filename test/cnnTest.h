#include "gtest/gtest.h"
#include "CNNProcessor.h"

// Test fixture for CNNProcessor class
class CNNProcessorTest : public ::testing::Test {
protected:
    CNNProcessorSettings settings;
    CNNProcessor processor;

    CNNProcessorTest() : settings{"model_path", 32, 32}, processor(settings) {}
};

// Tests that the CNNProcessor can correctly load a model from a file
TEST_F(CNNProcessorTest, LoadModelTest) {
    processor.LoadModel("model/pose-mobilenetv2.pb");
    // Check that the network was loaded successfully
    ASSERT_FALSE(processor.net.empty());
}

// Tests that the MakeBlob method returns the expected output for a given input scene
TEST_F(CNNProcessorTest, MakeBlobTest) {
    Scene scene;
    scene.regionOfInterest = {{0, 0}, {64, 64}};
    scene.frame = cv::Mat(64, 64, CV_8UC3, cv::Scalar(255, 0, 0));
    cv::Mat expectedBlob = cv::Mat(1, 3, CV_32F, {1, 0, 0});
    cv::Mat actualBlob = processor.MakeBlob(scene);
    // Check that the MakeBlob method returns the expected output
    ASSERT_TRUE(cv::norm(actualBlob, expectedBlob, cv::NORM_L2) < 1e-5);
}

// Tests that the ProcessScene method correctly classifies a scene
TEST_F(CNNProcessorTest, ProcessSceneTest) {
    Scene scene;
    scene.regionOfInterest = {{0, 0}, {32, 32}};
    scene.frame = cv::Mat(32, 32, CV_8UC3, cv::Scalar(0, 0, 255));
    Scene processedScene = processor.ProcessScene(scene);
    // Check that the scene was classified correctly
  TEST(cnnprocessor_test, checkResult_f){
    CNNProcessor cnn(gymBuddi::getModelPath());
    Scene out = cnn.ProcessScene(MakeScene("Plank"));
    EXPECT_EQ(out.result, "Plank");
}
