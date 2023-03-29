#include <gtest/gtest.h>
#include <QApplication>
#include <QPushButton>

// Define a test case
TEST_F(ResetPushButtonTest, test_reset) {
  // Set the button text to "Clicked"
  button_.setText("Clicked");

  // Click the button
  QTest::mouseClick(&button_, Qt::LeftButton);

  // Check if the button text is now "Reset"
  EXPECT_EQ(button_.text(), "Reset");

  // Click the button again
  QTest::mouseClick(&button_, Qt::LeftButton);

  // Check if the button text is now "Clicked"
  EXPECT_EQ(button_.text(), "Clicked");
}