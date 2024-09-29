// 641. Design Circular Deque
// Design your implementation of the circular double-ended queue (deque).

// Implement the MyCircularDeque class:

// MyCircularDeque(int k) Initializes the deque with a maximum size of k.
// boolean insertFront() Adds an item at the front of Deque. 
// Returns true if the operation is successful, or false otherwise.
// boolean insertLast() Adds an item at the rear of Deque. 
// Returns true if the operation is successful, or false otherwise.
// boolean deleteFront() Deletes an item from the front of Deque. 
// Returns true if the operation is successful, or false otherwise.
// boolean deleteLast() Deletes an item from the rear of Deque. 
// Returns true if the operation is successful, or false otherwise.
// int getFront() Returns the front item from the Deque. 
// Returns -1 if the deque is empty.
// int getRear() Returns the last item from Deque. 
// Returns -1 if the deque is empty.
// boolean isEmpty() Returns true if the deque is empty, or false otherwise.
// boolean isFull() Returns true if the deque is full, or false otherwise.

// Explanation:
// - We need to implement a circular deque with a fixed capacity (k).
// - A deque allows inserting and deleting items from both the front and rear ends.
// - The operations should work efficiently within the bounds of the deque's capacity.
// - We'll keep track of the current size of the deque and the indices for the front and rear.
// - We maintain an array of size `k` to store the elements of the deque.
// - We use two pointers, `front` and `rear`, to point to the start and end of the deque.
// - The deque is circular, so we use modulo arithmetic to wrap around when the indices exceed the bounds of the array.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *deque;  // Array to hold deque elements
    int front;   // Index of the front element
    int rear;    // Index of the rear element
    int size;    // Current size of the deque
    int capacity; // Maximum capacity of the deque
} MyCircularDeque;

// Initializes the deque with a maximum size of k
MyCircularDeque* myCircularDequeCreate(int k) {
    MyCircularDeque *obj = (MyCircularDeque*)malloc(sizeof(MyCircularDeque));
    obj->deque = (int*)malloc(k * sizeof(int));  // Create an array of size k
    obj->front = 0;
    obj->rear = 0;
    obj->size = 0;
    obj->capacity = k;
    return obj;
}

// Adds an item at the front of Deque
bool myCircularDequeInsertFront(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity) return false;  // Deque is full
    obj->front = (obj->front - 1 + obj->capacity) % obj->capacity; // Move front pointer backwards
    obj->deque[obj->front] = value;  // Insert value at the front
    obj->size++;
    return true;
}

// Adds an item at the rear of Deque
bool myCircularDequeInsertLast(MyCircularDeque* obj, int value) {
    if (obj->size == obj->capacity) return false;  // Deque is full
    obj->deque[obj->rear] = value;  // Insert value at the rear
    obj->rear = (obj->rear + 1) % obj->capacity;  // Move rear pointer forwards
    obj->size++;
    return true;
}

// Deletes an item from the front of Deque
bool myCircularDequeDeleteFront(MyCircularDeque* obj) {
    if (obj->size == 0) return false;  // Deque is empty
    obj->front = (obj->front + 1) % obj->capacity;  // Move front pointer forwards
    obj->size--;
    return true;
}

// Deletes an item from the rear of Deque
bool myCircularDequeDeleteLast(MyCircularDeque* obj) {
    if (obj->size == 0) return false;  // Deque is empty
    obj->rear = (obj->rear - 1 + obj->capacity) % obj->capacity;  // Move rear pointer backwards
    obj->size--;
    return true;
}

// Returns the front item from the Deque
int myCircularDequeGetFront(MyCircularDeque* obj) {
    if (obj->size == 0) return -1;  // Deque is empty
    return obj->deque[obj->front];  // Return the front element
}

// Returns the last item from Deque
int myCircularDequeGetRear(MyCircularDeque* obj) {
    if (obj->size == 0) return -1;  // Deque is empty
    return obj->deque[(obj->rear - 1 + obj->capacity) % obj->capacity];  // Return the rear element
}

// Returns true if the deque is empty
bool myCircularDequeIsEmpty(MyCircularDeque* obj) {
    return obj->size == 0;
}

// Returns true if the deque is full
bool myCircularDequeIsFull(MyCircularDeque* obj) {
    return obj->size == obj->capacity;
}

// Frees the allocated memory
void myCircularDequeFree(MyCircularDeque* obj) {
    free(obj->deque);
    free(obj);
}

// Your MyCircularDeque object will be instantiated and called as such:
// MyCircularDeque* obj = myCircularDequeCreate(k);
// bool param_1 = myCircularDequeInsertFront(obj, value);
// bool param_2 = myCircularDequeInsertLast(obj, value);
// bool param_3 = myCircularDequeDeleteFront(obj);
// bool param_4 = myCircularDequeDeleteLast(obj);
// int param_5 = myCircularDequeGetFront(obj);
// int param_6 = myCircularDequeGetRear(obj);
// bool param_7 = myCircularDequeIsEmpty(obj);
// bool param_8 = myCircularDequeIsFull(obj);
// myCircularDequeFree(obj);
