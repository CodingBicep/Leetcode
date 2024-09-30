// 1381. Design a Stack With Increment Operation
// Design a stack that supports increment operations on its elements.
// 
// Implement the CustomStack class:
// 
// CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
// void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
// int pop() Pops and returns the top of the stack or -1 if the stack is empty.
// void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.
// 
// Example 1:
// 
// Input
// ["CustomStack","push","push","pop","push","push","push","increment","increment","pop","pop","pop","pop"]
// [[3],[1],[2],[],[2],[3],[4],[5,100],[2,100],[],[],[],[]]
// Output
// [null,null,null,2,null,null,null,null,null,103,202,201,-1]
// 
// Explanation:
// CustomStack stk = new CustomStack(3); // Stack is Empty []
// stk.push(1);                          // stack becomes [1]
// stk.push(2);                          // stack becomes [1, 2]
// stk.pop();                            // return 2 --> Return top of the stack 2, stack becomes [1]
// stk.push(2);                          // stack becomes [1, 2]
// stk.push(3);                          // stack becomes [1, 2, 3]
// stk.push(4);                          // stack still [1, 2, 3], Do not add another element as size is 3
// stk.increment(5, 100);                // stack becomes [101, 102, 103]
// stk.increment(2, 100);                // stack becomes [201, 202, 103]
// stk.pop();                            // return 103 --> Return top of the stack 103, stack becomes [201, 202]
// stk.pop();                            // return 202 --> Return top of the stack 202, stack becomes [201]
// stk.pop();                            // return 201 --> Return top of the stack 201, stack becomes []
// stk.pop();                            // return -1 --> Stack is empty return -1
//
// Explanation:
// In C++, the CustomStack class is used to handle typical stack operations but with the added functionality of incrementing the bottom k elements.

class CustomStack {
    vector<int> stack;
    vector<int> increment;
    int maxSize;

public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
        increment.resize(maxSize, 0);
    }

    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }

    int pop() {
        if (stack.empty()) {
            return -1;
        }
        int index = stack.size() - 1;
        int result = stack.back() + increment[index];
        if (index > 0) {
            increment[index - 1] += increment[index];
        }
        increment[index] = 0;
        stack.pop_back();
        return result;
    }

    void increment(int k, int val) {
        int limit = min(k, (int)stack.size()) - 1;
        if (limit >= 0) {
            increment[limit] += val;
        }
    }
};
