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
// The CustomStack class allows us to manipulate a limited size stack. You can push elements to the stack until it reaches maxSize.
// The pop method removes the top element or returns -1 if the stack is empty. The increment method increases the bottom k elements by val.

class CustomStack {

    private int[] stack;
    private int[] increment;
    private int top;

    public CustomStack(int maxSize) {
        stack = new int[maxSize];
        increment = new int[maxSize];
        top = -1;
    }

    public void push(int x) {
        if (top < stack.length - 1) {
            top++;
            stack[top] = x;
        }
    }

    public int pop() {
        if (top == -1) {
            return -1;
        }
        int result = stack[top] + increment[top];
        if (top > 0) {
            increment[top - 1] += increment[top];
        }
        increment[top] = 0;
        top--;
        return result;
    }

    public void increment(int k, int val) {
        int limit = Math.min(k, top + 1) - 1;
        if (limit >= 0) {
            increment[limit] += val;
        }
    }
}
