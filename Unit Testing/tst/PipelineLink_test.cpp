#include "PipelineLink.h"
#include <gtest/gtest.h>

class ScenePipelineLinkTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Set up any required resources before each test is run.
        scene_pipeline_link_ = new ScenePipelineLink();
    }

    void TearDown() override {
        // Clean up any resources allocated in SetUp().
        delete scene_pipeline_link_;
    }

    // Pointer to the scene pipeline link being tested.
    ScenePipelineLink* scene_pipeline_link_;
};

// Test that the scene pipeline link initializes correctly.
TEST_F(ScenePipelineLinkTest, Initialize) {
    EXPECT_TRUE(scene_pipeline_link_->Initialize());
}

// Test that the scene pipeline link processes a scene correctly.
TEST_F(ScenePipelineLinkTest, ProcessScene) {
    // Load a scene for processing.
    Scene scene = LoadSceneFromFile("Scene.h");

    // Process the scene.
    Scene result = scene_pipeline_link_->ProcessScene(scene);

    // Check that the result is not empty.
    EXPECT_FALSE(result.objects.empty());
}