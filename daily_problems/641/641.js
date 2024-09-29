// 641. Design Circular Deque
// Design your implementation of the circular double-ended queue (deque).

// Implement the MyCircularDeque class:

// MyCircularDeque(int k) Initializes the deque with a maximum size of k.
// boolean insertFront(int value) Adds an item at the front of Deque. 
// Returns true if the operation is successful, or false otherwise.
// boolean insertLast(int value) Adds an item at the rear of Deque. 
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
// - The deque is circular, meaning when we reach the end of the deque, we can wrap around.
// - Use an array to store deque elements.
// - Keep two pointers: front and rear to track where to insert or delete elements.
// - Use modulo arithmetic to wrap around when the pointers go out of bounds of the array.
// - Track the current size of the deque and its capacity.

class MyCircularDeque {
    constructor(k) {
        this.capacity = k;  // Maximum capacity of the deque
        this.size = 0;      // Current size of the deque
        this.front = 0;     // Front pointer
        this.rear = k - 1;  // Rear pointer
        this.deque = new Array(k);  // The array to store deque elements
    }

    // Adds an item at the front of the deque
    insertFront(value) {
        if (this.isFull()) return false;  // Check if deque is full
        this.front = (this.front - 1 + this.capacity) % this.capacity;  // Move front pointer backward
        this.deque[this.front] = value;  // Insert the value at the front
        this.size++;
        return true;
    }

    // Adds an item at the rear of the deque
    insertLast(value) {
        if (this.isFull()) return false;  // Check if deque is full
        this.rear = (this.rear + 1) % this.capacity;  // Move rear pointer forward
        this.deque[this.rear] = value;  // Insert the value at the rear
        this.size++;
        return true;
    }

    // Deletes an item from the front of the deque
    deleteFront() {
        if (this.isEmpty()) return false;  // Check if deque is empty
        this.front = (this.front + 1) % this.capacity;  // Move front pointer forward
        this.size--;
        return true;
    }

    // Deletes an item from the rear of the deque
    deleteLast() {
        if (this.isEmpty()) return false;  // Check if deque is empty
        this.rear = (this.rear - 1 + this.capacity) % this.capacity;  // Move rear pointer backward
        this.size--;
        return true;
    }

    // Returns the front item from the deque
    getFront() {
        if (this.isEmpty()) return -1;  // Deque is empty
        return this.deque[this.front];
    }

    // Returns the last item from the deque
    getRear() {
        if (this.isEmpty()) return -1;  // Deque is empty
        return this.deque[this.rear];
    }

    // Returns true if the deque is empty
    isEmpty() {
        return this.size === 0;
    }

    // Returns true if the deque is full
    isFull() {
        return this.size === this.capacity;
    }
}

// Your MyCircularDeque object will be instantiated and called as such:
// var obj = new MyCircularDeque(k)
// var param_1 = obj.insertFront(value)
// var param_2 = obj.insertLast(value)
// var param_3 = obj.deleteFront()
// var param_4 = obj.deleteLast()
// var param_5 = obj.getFront()
// var param_6 = obj.getRear()
// var param_7 = obj.isEmpty()
// var param_8 = obj.isFull()
