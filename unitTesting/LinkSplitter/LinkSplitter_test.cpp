#include "LinkSplitter.h"
#include <gtest/gtest.h>

class LinkSplitterTest : public ::testing::Test {
protected:
    void SetUp() override {
        // Set up any required resources before each test is run.
        link_splitter_ = new LinkSplitter();
    }

    void TearDown() override {
        // Clean up any resources allocated in SetUp().
        delete link_splitter_;
    }

    // Pointer to the link splitter being tested.
    LinkSplitter* link_splitter_;
};

// Test that the link splitter initializes correctly.
TEST_F(LinkSplitterTest, Initialize) {
    EXPECT_TRUE(link_splitter_->Initialize());
}

// Test that the link splitter splits a link correctly.
TEST_F(LinkSplitterTest, SplitLink) {
    // Create a link to split.
    Link link;
    link.source_node = 0;
    link.destination_node = 1;
    link.weight = 0.5;

    // Split the link.
    std::vector<Link> result = link_splitter_->SplitLink(link);

    // Check that the result has two links with the same source and destination nodes.
    EXPECT_EQ(result.size(), 2);
    EXPECT_EQ(result[0].source_node, link.source_node);
    EXPECT_EQ(result[1].source_node, link.source_node);
    EXPECT_EQ(result[0].destination_node, link.destination_node);
    EXPECT_EQ(result[1].destination_node, link.destination_node);

    // Check that the weights of the split links add up to the weight of the original link.
    double total_weight = result[0].weight + result[1].weight;
    EXPECT_DOUBLE_EQ(total_weight, link.weight);
}