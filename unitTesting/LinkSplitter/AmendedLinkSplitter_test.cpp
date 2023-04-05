#include "gtest/gtest.h"
#include "LinkSplitter.h"
#include "PipelineLink.h"

// Create a mock SceneCallback that tracks how many times NextScene was called
class MockSceneCallback : public SceneCallback {
public:
    int numScenes = 0;

    void NextScene(Scene s) {
        numScenes++;
    }
};

// Unit test for LinkSplitter
TEST(LinkSplitterTest, TestNextScene) {
    // Create a LinkSplitter
    LinkSplitter splitter;

    // Create a primary callback and register it with the splitter
    MockSceneCallback primaryCallback;
    splitter.RegisterCallback(&primaryCallback);

    // Create a secondary callback and register it with the splitter
    MockSceneCallback secondaryCallback;
    splitter.RegisterSecondaryCallback(&secondaryCallback);

    // Create a Scene to pass through the splitter
    Scene s;
    s.frame = cv::Mat::zeros(cv::Size(100,100), CV_8UC3);

    // Call NextScene on the splitter
    splitter.NextScene(s);

    // Check that the primary callback was called once
    EXPECT_EQ(primaryCallback.numScenes, 1);

    // Check that the secondary callback was called once
    EXPECT_EQ(secondaryCallback.numScenes, 1);
}

