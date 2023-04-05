#include "Scene.h"
#include <gtest/gtest.h>

class SceneTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Set up any required resources before each test is run.
        scene_ = new Scene();
    }

    void TearDown() override {
        // Clean up any resources allocated in SetUp().
        delete scene_;
    }

    // Pointer to the scene being tested.
    Scene* scene_;
};

// Test that the scene initializes correctly.
TEST_F(SceneTest, Initialize) {
    EXPECT_TRUE(scene_->Initialize());
}

// Test that the scene processes data correctly.
TEST_F(SceneTest, ProcessData) {
    // Generate some test data.
    std::vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0};

    // Process the data.
    std::vector<double> result = scene_->ProcessData(data);

    // Check that the result has the same length as the input data.
    EXPECT_EQ(result.size(), data.size());

    // Check that the result has been filtered correctly.
    EXPECT_NEAR(result[0], 0.0, 1e-6);
    EXPECT_NEAR(result[1], 0.0, 1e-6);
    EXPECT_NEAR(result[2], 0.0, 1e-6);
    EXPECT_NEAR(result[3], 0.0, 1e-6);
    EXPECT_NEAR(result[4], 0.0, 1e-6);
}