#ifndef QUEUE_H
#define QUEUE_H

#include <stdexcept>

template <typename T>
class Queue {
public:
    Queue();
    ~Queue();
    
    // Push element to the back of queue
    void push(const T& value);
    
    // Remove and return element from the front of queue
    T pop();
    
    // Check if queue is empty
    bool isEmpty() const;
    
    // Get size of queue
    int size() const;
    
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };
    
    Node* front;
    Node* back;
    int count;
};

#endif // QUEUE_H
