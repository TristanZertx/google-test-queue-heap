#include <gtest/gtest.h>
#include "../include/heap.h"

// Test fixture for Heap (min-heap)
class HeapTest : public ::testing::Test {
protected:
    Heap<int> heap;
};

// Basic push/pop tests
TEST_F(HeapTest, PushAndPopSingleElement) {
    heap.push(42);
    EXPECT_EQ(heap.pop(), 42);
}

TEST_F(HeapTest, PushAndPopMultipleElements) {
    heap.push(5);
    heap.push(3);
    heap.push(7);
    
    EXPECT_EQ(heap.pop(), 3);
    EXPECT_EQ(heap.pop(), 5);
    EXPECT_EQ(heap.pop(), 7);
}

TEST_F(HeapTest, MinHeapOrder) {
    heap.push(15);
    heap.push(10);
    heap.push(20);
    heap.push(5);
    heap.push(8);
    
    EXPECT_EQ(heap.pop(), 5);
    EXPECT_EQ(heap.pop(), 8);
    EXPECT_EQ(heap.pop(), 10);
    EXPECT_EQ(heap.pop(), 15);
    EXPECT_EQ(heap.pop(), 20);
}

// Peek tests
TEST_F(HeapTest, PeekTopElement) {
    heap.push(10);
    heap.push(5);
    heap.push(15);
    
    EXPECT_EQ(heap.peek(), 5);
    EXPECT_EQ(heap.peek(), 5); // Peek should not remove
}

TEST_F(HeapTest, PeekDoesNotRemoveElement) {
    heap.push(42);
    int peeked = heap.peek();
    int popped = heap.pop();
    
    EXPECT_EQ(peeked, popped);
}

// Empty heap tests
TEST_F(HeapTest, IsEmptyOnCreation) {
    EXPECT_TRUE(heap.isEmpty());
}

TEST_F(HeapTest, IsNotEmptyAfterPush) {
    heap.push(10);
    EXPECT_FALSE(heap.isEmpty());
}

TEST_F(HeapTest, IsEmptyAfterPopAll) {
    heap.push(10);
    heap.pop();
    EXPECT_TRUE(heap.isEmpty());
}

// Size tests
TEST_F(HeapTest, SizeOnCreation) {
    EXPECT_EQ(heap.size(), 0);
}

TEST_F(HeapTest, SizeAfterPush) {
    heap.push(1);
    EXPECT_EQ(heap.size(), 1);
    heap.push(2);
    EXPECT_EQ(heap.size(), 2);
    heap.push(3);
    EXPECT_EQ(heap.size(), 3);
}

TEST_F(HeapTest, SizeAfterPop) {
    heap.push(1);
    heap.push(2);
    heap.push(3);
    heap.pop();
    EXPECT_EQ(heap.size(), 2);
    heap.pop();
    EXPECT_EQ(heap.size(), 1);
}

// Exception tests
TEST_F(HeapTest, PopFromEmptyHeapThrowsException) {
    EXPECT_THROW(heap.pop(), std::runtime_error);
}

TEST_F(HeapTest, PeekEmptyHeapThrowsException) {
    EXPECT_THROW(heap.peek(), std::runtime_error);
}

// Mixed operations tests
TEST_F(HeapTest, AlternatingPushAndPop) {
    heap.push(5);
    EXPECT_EQ(heap.pop(), 5);
    
    heap.push(3);
    heap.push(7);
    EXPECT_EQ(heap.pop(), 3);
    
    heap.push(1);
    EXPECT_EQ(heap.pop(), 1);
    EXPECT_EQ(heap.pop(), 7);
}

TEST_F(HeapTest, LargeNumberOfElements) {
    const int N = 100;
    
    // Push elements in reverse order
    for (int i = N; i > 0; --i) {
        heap.push(i);
    }
    
    EXPECT_EQ(heap.size(), N);
    
    // Pop should return in sorted order (min-heap)
    for (int i = 1; i <= N; ++i) {
        EXPECT_EQ(heap.pop(), i);
    }
    
    EXPECT_TRUE(heap.isEmpty());
}

TEST_F(HeapTest, DuplicateElements) {
    heap.push(5);
    heap.push(5);
    heap.push(5);
    
    EXPECT_EQ(heap.pop(), 5);
    EXPECT_EQ(heap.pop(), 5);
    EXPECT_EQ(heap.pop(), 5);
}

TEST_F(HeapTest, NegativeNumbers) {
    heap.push(-5);
    heap.push(10);
    heap.push(-20);
    heap.push(0);
    
    EXPECT_EQ(heap.pop(), -20);
    EXPECT_EQ(heap.pop(), -5);
    EXPECT_EQ(heap.pop(), 0);
    EXPECT_EQ(heap.pop(), 10);
}

// Test with different data types
class HeapDoubleTest : public ::testing::Test {
protected:
    Heap<double> heap;
};

TEST_F(HeapDoubleTest, PushAndPopDoubles) {
    heap.push(3.14);
    heap.push(2.71);
    heap.push(1.41);
    
    EXPECT_DOUBLE_EQ(heap.pop(), 1.41);
    EXPECT_DOUBLE_EQ(heap.pop(), 2.71);
    EXPECT_DOUBLE_EQ(heap.pop(), 3.14);
}

TEST_F(HeapDoubleTest, DoubleMinHeapOrder) {
    heap.push(5.5);
    heap.push(2.2);
    heap.push(8.8);
    heap.push(1.1);
    
    EXPECT_DOUBLE_EQ(heap.pop(), 1.1);
    EXPECT_DOUBLE_EQ(heap.pop(), 2.2);
    EXPECT_DOUBLE_EQ(heap.pop(), 5.5);
    EXPECT_DOUBLE_EQ(heap.pop(), 8.8);
}
