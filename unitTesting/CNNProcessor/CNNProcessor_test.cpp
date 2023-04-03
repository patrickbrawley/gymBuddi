#include "CNNProcessor.h"
#include <gtest/gtest.h>

class CnnProcessorTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Set up any required resources before each test is run.
        cnn_processor_ = new CnnProcessor();
    }

    void TearDown() override {
        // Clean up any resources allocated in SetUp().
        delete cnn_processor_;
    }

    // Pointer to the CNN processor being tested.
    CnnProcessor* cnn_processor_;
};

// Test that the CNN processor initializes correctly.
TEST_F(CnnProcessorTest, Initialize) {
    EXPECT_TRUE(cnn_processor_->Initialize());
}

// Test that the CNN processor processes an image correctly.
TEST_F(CnnProcessorTest, ProcessImage) {
    // Load an image for processing.
    cv::Mat image = cv::imread("test_image.png", cv::IMREAD_GRAYSCALE);

    // Process the image.
    cv::Mat result = cnn_processor_->ProcessImage(image);

    // Check that the result is not empty.
    EXPECT_FALSE(result.empty());
}





