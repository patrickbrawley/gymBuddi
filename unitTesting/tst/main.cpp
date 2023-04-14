// include all unit tests & googletest
#include "gtest/gtest.h"
#include "camera_test.cpp"
#include "cnnprocessor_test.cpp"
#include "countuptimer_test.cpp"
#include "linksplitter_test.cpp"
#include "pipelinelink_test.cpp"
#include "preprocessor_test.cpp"
#include "scene_test.cpp"

//run all unit tests
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}