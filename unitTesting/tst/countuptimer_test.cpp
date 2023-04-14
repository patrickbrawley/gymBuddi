/**
    @file countuptimer_test.cpp
    @brief This file contains the unit test for the CountUpTimer class.
*/
#include "countuptimer.h"
#include <gtest/gtest.h>

/**
    @brief Tests the basic functionality of the CountUpTimer class.
*/
TEST(CountUpTimerTest, BasicTest)
{
    CountUpTimer timer;

    const int startValue = 0; /*< Define the expected start and end values >*/
    const int endValue = 10;
    const int increment = 1;

    const int expectedNumUpdates = endValue - startValue + 1; /*< Define the expected number of updates >*/

    int numUpdates = 0; /*> Define the update and finished callbacks >*/
    bool finishedCallbackCalled = false;
    std::function<void(int)> updateCallback = [&](int value)
    {
        numUpdates++;
        EXPECT_GE(value, startValue);
        EXPECT_LE(value, endValue);
    };
    std::function<void()> finishedCallback = &
    {
        finishedCallbackCalled = true;
    };

    timer.start(startValue, endValue, increment, updateCallback, finishedCallback); /*< Start the timer >*/

    while (!finishedCallbackCalled) /*< Wait for the timer to finish >*/
    {
        QCoreApplication::processEvents();
    }

    EXPECT_EQ(numUpdates, expectedNumUpdates); /*< Check that the expected number of updates were received >*/

    timer.stop(); /*< Stop the timer >*/
}