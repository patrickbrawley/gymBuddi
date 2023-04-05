#include <gtest/gtest.h>
#include <chrono>
#include <thread>
#include "CountUpTimer.h"

// Define a fixture for the test case
class CountUpTimerTest : public ::testing::Test {
protected:
  // Define any necessary variables and objects
  CountUpTimer timer_;
};

// Define a test case
TEST_F(CountUpTimerTest, ElapsedTimeTest) {
  // Start the timer
  timer_.start();

  // Wait for some time
  std::this_thread::sleep_for(std::chrono::milliseconds(1000));

  // Stop the timer and get the elapsed time
  double elapsed_time = timer_.stop();

  // Check if the elapsed time is approximately 1 second
  EXPECT_NEAR(elapsed_time, 1.0, 0.01);
}