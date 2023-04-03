// include all unit tests & googletest
#include "gtest/gtest.h"
#include "CNNProcessor_test.cpp"
#include "LinkSplitter_test.cpp"
#include "PreProcessor_test.cpp"
#include "PipelineLink_test.cpp"
#include "test_camera.cpp"
#include "CountUpTimerTest.cpp"
#include "Scene_test.cpp"

//run all unit tests
int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}