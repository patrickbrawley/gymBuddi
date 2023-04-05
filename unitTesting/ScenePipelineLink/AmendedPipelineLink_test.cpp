#include "PipelineLink.h"
#include <gtest/gtest.h>

// Define a mock SceneCallback class for testing purposes
class MockSceneCallback : public SceneCallback {
public:
    MOCK_METHOD(void, NextScene, (Scene));
};

TEST(PipelineLinkTest, TestNextSceneCallsRegisteredCallback) {
    // Create a PipelineLink object and a mock SceneCallback object
    PipelineLink link;
    MockSceneCallback callback;
    
    // Register the mock SceneCallback object with the PipelineLink object
    link.RegisterCallback(&callback);
    
    // Expect the NextScene method of the mock SceneCallback object to be called with a scene object
    EXPECT_CALL(callback, NextScene(_))
        .WillOnce(testing::Return());
    
    // Call the NextScene method of the PipelineLink object with a scene object
    link.NextScene(Scene());
}

TEST(PipelineLinkTest, TestNextSceneDoesNotCallUnregisteredCallback) {
    // Create a PipelineLink object and a mock SceneCallback object
    PipelineLink link;
    MockSceneCallback callback;
    
    // Do not register the mock SceneCallback object with the PipelineLink object
    
    // Expect the NextScene method of the mock SceneCallback object not to be called
    EXPECT_CALL(callback, NextScene(_))
        .Times(0);
    
    // Call the NextScene method of the PipelineLink object with a scene object
    link.NextScene(Scene());
}
