#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <stdexcept>

template <typename T>
class Heap {
public:
    Heap();
    ~Heap();
    
    // Push element to heap
    void push(const T& value);
    
    // Remove and return the top element (min or max depending on comparator)
    T pop();
    
    // Get the top element without removing
    T peek() const;
    
    // Check if heap is empty
    bool isEmpty() const;
    
    // Get size of heap
    int size() const;
    
private:
    std::vector<T> elements;
    
    // Helper functions for heap operations
    int parent(int index) const;
    int leftChild(int index) const;
    int rightChild(int index) const;
    
    void heapifyUp(int index);
    void heapifyDown(int index);
};

#endif // HEAP_H
