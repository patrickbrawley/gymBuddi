/**
    @file PipelineLinkTest.cpp
    @brief Unit tests for the PipelineLink class
*/
#include "PipelineLink.h"
#include <gtest/gtest.h>

/**
    @brief Define a mock SceneCallback class for testing purposes
*/
class MockSceneCallback : public SceneCallback {
public:
    MOCK_METHOD(void, NextScene, (Scene));
};

/**
    @brief Unit test for PipelineLink::NextScene() method when a callback is registered
*/

TEST(PipelineLinkTest, TestNextSceneCallsRegisteredCallback) {
    PipelineLink link; /*< Create a PipelineLink object and a mock SceneCallback object >*/
    MockSceneCallback callback;

    link.RegisterCallback(&callback); /*< Register the mock SceneCallback object with the PipelineLink object >*/

    EXPECT_CALL(callback, NextScene(_)) /*< Expect the NextScene method of the mock SceneCallback object to be called with a scene object >*/
        .WillOnce(testing::Return());

    link.NextScene(Scene()); /*< Call the NextScene method of the PipelineLink object with a scene object >*/

}

/**
    @brief Unit test for PipelineLink::NextScene() method when no callback is registered
*/

TEST(PipelineLinkTest, TestNextSceneDoesNotCallUnregisteredCallback) {
    PipelineLink link; /*< Create a PipelineLink object and a mock SceneCallback object >*/
    MockSceneCallback callback;

    /*< NOTE - Do not register the mock SceneCallback object with the PipelineLink object >*/

    EXPECT_CALL(callback, NextScene(_)) /*< Expect the NextScene method of the mock SceneCallback object not to be called >*/
        .Times(0);

    link.NextScene(Scene()); /*< Call the NextScene method of the PipelineLink object with a scene object >*/

}
