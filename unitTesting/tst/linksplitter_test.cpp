/**
    @file linksplitter_test.cpp
    @brief This contains the unit test for LinkSplitter class.
*/
#include "gtest/gtest.h"
#include "LinkSplitter.h"
#include "ConcreteLinkSplitter.h"
#include "PipelineLink.h"

/**
    @brief Create a mock SceneCallback that tracks how many times NextScene was called
*/
class MockSceneCallback : public SceneCallback {
public:
    int numScenes = 0;

    /**
        @brief Implementation of the NextScene function
        @param s The Scene to be processed
    */
    void NextScene(Scene s) {
    numScenes++;
    }
};

/**
    @brief Unit test for LinkSplitter class
*/

TEST(LinkSplitterTest, TestNextScene) {
    
    ConcreteLinkSplitter splitter; /*< Create a LinkSplitter >*/


    MockSceneCallback primaryCallback; /*< Create a primary callback and register it with the splitter >*/
    splitter.setCallback(&primaryCallback);

    MockSceneCallback secondaryCallback; /*< Create a secondary callback and register it with the splitter >*/
    splitter.RegisterSecondaryCallback(&secondaryCallback);

    Scene s; /*< Create a Scene to pass through the splitter >*/
    s.frame = cv::Mat::zeros(cv::Size(100,100), CV_8UC3);

    splitter.NextScene(s); /*< Call NextScene on the splitter >*/

    EXPECT_EQ(primaryCallback.numScenes, 1); /*< Check that the primary callback was called once >*/
    EXPECT_EQ(secondaryCallback.numScenes, 1); /*< Check that the secondary callback was called once >*/ 
}






