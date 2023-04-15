/**
    @brief This file runs all of the unit tests using googletest 
*/

#include "gtest/gtest.h"
#include "camera_test.cpp"
#include "cnnprocessor_test.cpp"
#include "countuptimer_test.cpp"
#include "linksplitter_test.cpp"
#include "pipelinelink_test.cpp"
#include "preprocessor_test.cpp"
#include "scene_test.cpp"

int main(int argc, char **argv) { /*< This runs all unit tests listed above >*/
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}