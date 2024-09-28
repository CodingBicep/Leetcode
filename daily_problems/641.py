# Question:

# 641. Design Circular Deque
# Design your implementation of the circular double-ended queue (deque).

# Implement the MyCircularDeque class:

# MyCircularDeque(int k) Initializes the deque with a maximum size of k.
# boolean insertFront() Adds an item at the front of Deque. 
# Returns true if the operation is successful, or false otherwise.
# boolean insertLast() Adds an item at the rear of Deque. 
# Returns true if the operation is successful, or false otherwise.
# boolean deleteFront() Deletes an item from the front of Deque. 
# Returns true if the operation is successful, or false otherwise.
# boolean deleteLast() Deletes an item from the rear of Deque. 
# Returns true if the operation is successful, or false otherwise.
# int getFront() Returns the front item from the Deque. 
# Returns -1 if the deque is empty.
# int getRear() Returns the last item from Deque. 
# Returns -1 if the deque is empty.
# boolean isEmpty() Returns true if the deque is empty, or false otherwise.
# boolean isFull() Returns true if the deque is full, or false otherwise.


# Explanation:
# - We need to implement a circular deque with a fixed capacity (k).
# - A deque allows inserting and deleting items from both the front and rear ends.
# - The operations should work efficiently within the bounds of the deque's capacity.
# - We'll keep track of the current size of the deque and the indices for the front and rear.

# Approach:
# 1. We maintain an array of size `k` to store the elements of the deque.
# 2. We use two pointers, `front` and `rear`, to point to the start and end of the deque.
#    - `front`: tracks the position where we insert/delete from the front.
#    - `rear`: tracks the position where we insert/delete from the rear.
# 3. We also keep track of the current size of the deque with a variable `size`.
# 4. The deque is circular, so we use modulo arithmetic to wrap around when the indices exceed the bounds of the array.
#    - For example, if `rear` moves beyond the end of the array, it wraps around to the start of the array.
# 5. We implement methods to insert at the front, insert at the rear, delete from the front, delete from the rear, 
#    and retrieve the front and rear items. We also implement methods to check if the deque is empty or full.



class MyCircularDeque:

    def __init__(self, k: int):
        self.k = k
        self.deque = [0] * k
        self.front = 0
        self.rear = 0
        self.size = 0

    def insertFront(self, value: int) -> bool:
        if self.isFull():
            return False
        self.front = (self.front - 1) % self.k
        self.deque[self.front] = value
        self.size += 1
        return True

    def insertLast(self, value: int) -> bool:
        if self.isFull():
            return False
        self.deque[self.rear] = value
        self.rear = (self.rear + 1) % self.k
        self.size += 1
        return True

    def deleteFront(self) -> bool:
        if self.isEmpty():
            return False
        self.front = (self.front + 1) % self.k
        self.size -= 1
        return True

    def deleteLast(self) -> bool:
        if self.isEmpty():
            return False
        self.rear = (self.rear - 1) % self.k
        self.size -= 1
        return True

    def getFront(self) -> int:
        if self.isEmpty():
            return -1
        return self.deque[self.front]

    def getRear(self) -> int:
        if self.isEmpty():
            return -1
        return self.deque[(self.rear - 1) % self.k]

    def isEmpty(self) -> bool:
        return self.size == 0

    def isFull(self) -> bool:
        return self.size == self.k

# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()