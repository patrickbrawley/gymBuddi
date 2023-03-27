#include <gtest/gtest.h>
#include "Camera.h"

class MockSceneCallback : public SceneCallback {
public:
    MOCK_METHOD(void, NextScene, (const Scene&));
};

class CameraTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Set up the mock scene callback
        sceneCallback = std::make_unique<MockSceneCallback>();
    }

    void TearDown() override {
        // Reset the scene callback
        sceneCallback.reset();
    }

    std::unique_ptr<MockSceneCallback> sceneCallback;
};

TEST_F(CameraTest, DefaultConstructor) {
    Camera camera;
    EXPECT_TRUE(camera.getOn());
}

TEST_F(CameraTest, ConstructorFromSettings) {
    CameraSettings settings;
    settings.deviceID = 0;
    settings.apiID = cv::CAP_ANY;

    Camera camera(settings);
    EXPECT_TRUE(camera.getOn());
}

TEST_F(CameraTest, SetOn) {
    Camera camera;
    camera.setOn(false);
    EXPECT_FALSE(camera.getOn());
}

TEST_F(CameraTest, PostFrame) {
    Camera camera;
    cv::Mat image(480, 640, CV_8UC3);
    Scene expectedScene;
    expectedScene.frame = image.clone();

    EXPECT_CALL(*sceneCallback, NextScene(expectedScene));

    // Call postFrame with a mock scene callback
    camera.sceneCallback = sceneCallback.get();
    camera.postFrame();
}

TEST_F(CameraTest, StartAndStop) {
    Camera camera;
    camera.Start();
    EXPECT_TRUE(camera.getOn());

    camera.Stop();
    EXPECT_FALSE(camera.getOn());
}
