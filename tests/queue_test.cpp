#include <gtest/gtest.h>
#include "../include/queue.h"

// Test fixture for Queue
class QueueTest : public ::testing::Test {
protected:
    Queue<int> queue;
};

// Basic push/pop tests
TEST_F(QueueTest, PushAndPopSingleElement) {
    queue.push(42);
    EXPECT_EQ(queue.pop(), 42);
}

TEST_F(QueueTest, PushAndPopMultipleElements) {
    queue.push(1);
    queue.push(2);
    queue.push(3);
    
    EXPECT_EQ(queue.pop(), 1);
    EXPECT_EQ(queue.pop(), 2);
    EXPECT_EQ(queue.pop(), 3);
}

TEST_F(QueueTest, FIFOOrder) {
    for (int i = 0; i < 5; ++i) {
        queue.push(i);
    }
    
    for (int i = 0; i < 5; ++i) {
        EXPECT_EQ(queue.pop(), i);
    }
}

// Empty queue tests
TEST_F(QueueTest, IsEmptyOnCreation) {
    EXPECT_TRUE(queue.isEmpty());
}

TEST_F(QueueTest, IsNotEmptyAfterPush) {
    queue.push(10);
    EXPECT_FALSE(queue.isEmpty());
}

TEST_F(QueueTest, IsEmptyAfterPopAll) {
    queue.push(10);
    queue.pop();
    EXPECT_TRUE(queue.isEmpty());
}

// Size tests
TEST_F(QueueTest, SizeOnCreation) {
    EXPECT_EQ(queue.size(), 0);
}

TEST_F(QueueTest, SizeAfterPush) {
    queue.push(1);
    EXPECT_EQ(queue.size(), 1);
    queue.push(2);
    EXPECT_EQ(queue.size(), 2);
}

TEST_F(QueueTest, SizeAfterPop) {
    queue.push(1);
    queue.push(2);
    queue.pop();
    EXPECT_EQ(queue.size(), 1);
}

// Exception tests
TEST_F(QueueTest, PopFromEmptyQueueThrowsException) {
    EXPECT_THROW(queue.pop(), std::runtime_error);
}

// Mixed operations tests
TEST_F(QueueTest, AlternatingPushAndPop) {
    queue.push(1);
    EXPECT_EQ(queue.pop(), 1);
    
    queue.push(2);
    queue.push(3);
    EXPECT_EQ(queue.pop(), 2);
    
    queue.push(4);
    EXPECT_EQ(queue.pop(), 3);
    EXPECT_EQ(queue.pop(), 4);
}

TEST_F(QueueTest, LargeNumberOfElements) {
    const int N = 1000;
    
    for (int i = 0; i < N; ++i) {
        queue.push(i);
    }
    
    EXPECT_EQ(queue.size(), N);
    
    for (int i = 0; i < N; ++i) {
        EXPECT_EQ(queue.pop(), i);
    }
    
    EXPECT_TRUE(queue.isEmpty());
}

// Test with different data types
class QueueStringTest : public ::testing::Test {
protected:
    Queue<std::string> queue;
};

TEST_F(QueueStringTest, PushAndPopStrings) {
    queue.push("hello");
    queue.push("world");
    
    EXPECT_EQ(queue.pop(), "hello");
    EXPECT_EQ(queue.pop(), "world");
}

TEST_F(QueueStringTest, StringFIFOOrder) {
    queue.push("first");
    queue.push("second");
    queue.push("third");
    
    EXPECT_EQ(queue.pop(), "first");
    EXPECT_EQ(queue.pop(), "second");
    EXPECT_EQ(queue.pop(), "third");
}
