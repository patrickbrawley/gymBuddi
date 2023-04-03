#include "PreProcessor.h"
#include <gtest/gtest.h>

class PreProcessorTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Set up any required resources before each test is run.
        pre_processor_ = new PreProcessor();
    }

    void TearDown() override {
        // Clean up any resources allocated in SetUp().
        delete pre_processor_;
    }

    // Pointer to the pre-processor being tested.
    PreProcessor* pre_processor_;
};

// Test that the pre-processor initializes correctly.
TEST_F(PreProcessorTest, Initialize) {
    EXPECT_TRUE(pre_processor_->Initialize());
}

// Test that the pre-processor processes data correctly.
TEST_F(PreProcessorTest, ProcessData) {
    // Generate some test data.
    std::vector<double> data = {1.0, 2.0, 3.0, 4.0, 5.0};

    // Process the data.
    std::vector<double> result = pre_processor_->ProcessData(data);

    // Check that the result has the same length as the input data.
    EXPECT_EQ(result.size(), data.size());

    // Check that the result has been normalized to have zero mean and unit variance.
    double mean = 0.0;
    double variance = 0.0;
    for (int i = 0; i < result.size(); ++i) {
        mean += result[i];
        variance += (result[i] - 1.0) * (result[i] - 1.0);
    }
    mean /= result.size();
    variance /= result.size();
    EXPECT_NEAR(mean, 0.0, 1e-6);
    EXPECT_NEAR(variance, 1.0, 1e-6);
}