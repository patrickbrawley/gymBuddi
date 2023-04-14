#include "countuptimer.h"
#include <gtest/gtest.h>

TEST(CountUpTimerTest, BasicTest)
{
    CountUpTimer timer;

    // Define the expected start and end values
    const int startValue = 0;
    const int endValue = 10;
    const int increment = 1;

    // Define the expected number of updates
    const int expectedNumUpdates = endValue - startValue + 1;

    // Define the update and finished callbacks
    int numUpdates = 0;
    bool finishedCallbackCalled = false;
    std::function<void(int)> updateCallback = [&](int value)
    {
        numUpdates++;
        EXPECT_GE(value, startValue);
        EXPECT_LE(value, endValue);
    };
    std::function<void()> finishedCallback = [&]()
    {
        finishedCallbackCalled = true;
    };

    // Start the timer
    timer.start(startValue, endValue, increment, updateCallback, finishedCallback);

    // Wait for the timer to finish
    while (!finishedCallbackCalled)
    {
        QCoreApplication::processEvents();
    }

    // Check that the expected number of updates were received
    EXPECT_EQ(numUpdates, expectedNumUpdates);

    // Stop the timer
    timer.stop();
}

