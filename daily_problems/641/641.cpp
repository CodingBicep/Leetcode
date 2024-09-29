// 641. Design Circular Deque
// Design your implementation of the circular double-ended queue (deque).

// Implement the MyCircularDeque class:

// MyCircularDeque(int k) Initializes the deque with a maximum size of k.
// bool insertFront(int value) Adds an item at the front of Deque. 
// Returns true if the operation is successful, or false otherwise.
// bool insertLast(int value) Adds an item at the rear of Deque. 
// Returns true if the operation is successful, or false otherwise.
// bool deleteFront() Deletes an item from the front of Deque. 
// Returns true if the operation is successful, or false otherwise.
// bool deleteLast() Deletes an item from the rear of Deque. 
// Returns true if the operation is successful, or false otherwise.
// int getFront() Returns the front item from the Deque. 
// Returns -1 if the deque is empty.
// int getRear() Returns the last item from Deque. 
// Returns -1 if the deque is empty.
// bool isEmpty() Returns true if the deque is empty, or false otherwise.
// bool isFull() Returns true if the deque is full, or false otherwise.

// Explanation:
// - The deque is circular, meaning when we reach the end of the deque, we can wrap around.
// - Use an array to store deque elements.
// - Keep two pointers: front and rear to track where to insert or delete elements.
// - Use modulo arithmetic to wrap around when the pointers go out of bounds of the array.
// - Track the current size of the deque and its capacity.

#include <vector>

class MyCircularDeque {
public:
    // Initializes the deque with a maximum size of k
    MyCircularDeque(int k) : capacity(k), size(0), front(0), rear(k - 1), deque(k, 0) {}

    // Adds an item at the front of the deque
    bool insertFront(int value) {
        if (isFull()) return false;  // Check if deque is full
        front = (front - 1 + capacity) % capacity;  // Move front pointer backwards
        deque[front] = value;  // Insert the value at the front
        ++size;
        return true;
    }

    // Adds an item at the rear of the deque
    bool insertLast(int value) {
        if (isFull()) return false;  // Check if deque is full
        rear = (rear + 1) % capacity;  // Move rear pointer forward
        deque[rear] = value;  // Insert the value at the rear
        ++size;
        return true;
    }

    // Deletes an item from the front of the deque
    bool deleteFront() {
        if (isEmpty()) return false;  // Check if deque is empty
        front = (front + 1) % capacity;  // Move front pointer forward
        --size;
        return true;
    }

    // Deletes an item from the rear of the deque
    bool deleteLast() {
        if (isEmpty()) return false;  // Check if deque is empty
        rear = (rear - 1 + capacity) % capacity;  // Move rear pointer backward
        --size;
        return true;
    }

    // Returns the front item from the deque
    int getFront() {
        if (isEmpty()) return -1;  // Deque is empty
        return deque[front];
    }

    // Returns the last item from the deque
    int getRear() {
        if (isEmpty()) return -1;  // Deque is empty
        return deque[rear];
    }

    // Returns true if the deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Returns true if the deque is full
    bool isFull() {
        return size == capacity;
    }

private:
    int capacity;  // Maximum capacity of the deque
    int size;      // Current size of the deque
    int front;     // Front pointer
    int rear;      // Rear pointer
    std::vector<int> deque;  // The array to store deque elements
};

// Your MyCircularDeque object will be instantiated and called as such:
// MyCircularDeque* obj = new MyCircularDeque(k);
// bool param_1 = obj->insertFront(value);
// bool param_2 = obj->insertLast(value);
// bool param_3 = obj->deleteFront();
// bool param_4 = obj->deleteLast();
// int param_5 = obj->getFront();
// int param_6 = obj->getRear();
// bool param_7 = obj->isEmpty();
// bool param_8 = obj->isFull();
