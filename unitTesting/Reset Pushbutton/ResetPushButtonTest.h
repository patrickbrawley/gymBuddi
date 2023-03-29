#include <gtest/gtest.h>
#include <QApplication>
#include <QPushButton>

// Define a fixture for the test case
class ResetButtonTest : public ::testing::Test {
protected:
  // Define any necessary variables and objects
  QApplication app_;
  QPushButton button_;
};