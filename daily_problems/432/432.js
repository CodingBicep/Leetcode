/*
432. All O`one Data Structure

Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

Implement the AllOne class:

AllOne() Initializes the object of the data structure.
inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. 
It is guaranteed that key exists in the data structure before the decrement.
getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
Note that each function must run in O(1) average time complexity.

Example 1:

Input
["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
[[], ["hello"], ["hello"], [], [], ["leet"], [], []]

Output
[null, null, null, "hello", "hello", null, "hello", "leet"]

Explanation:
AllOne allOne = new AllOne();
allOne.inc("hello");
allOne.inc("hello");
allOne.getMaxKey();  // return "hello"
allOne.getMinKey();  // return "hello"
allOne.inc("leet");
allOne.getMaxKey();  // return "hello"
allOne.getMinKey();  // return "leet"
*/

class ListNode {
    constructor() {
        this.count = 0;
        this.keys = new Set();
        this.prev = null;
        this.next = null;
    }
}

class AllOne {
    constructor() {
        this.keyCount = new Map();
        this.countToNode = new Map();
        this.head = new ListNode();
        this.tail = new ListNode();
        this.head.next = this.tail;
        this.tail.prev = this.head;
    }

    _insertNodeAfter(newNode, prevNode) {
        newNode.prev = prevNode;
        newNode.next = prevNode.next;
        prevNode.next.prev = newNode;
        prevNode.next = newNode;
    }

    inc(key) {
        let count = this.keyCount.get(key) || 0;
        this.keyCount.set(key, count + 1);
        let newCount = count + 1;

        if (!this.countToNode.has(newCount)) {
            let newNode = new ListNode();
            this.countToNode.set(newCount, newNode);
            this._insertNodeAfter(newNode, count === 0 ? this.head : this.countToNode.get(count));
        }

        this.countToNode.get(newCount).keys.add(key);
        
        if (count > 0) {
            this.countToNode.get(count).keys.delete(key);
            if (this.countToNode.get(count).keys.size === 0) {
                this._removeNode(this.countToNode.get(count));
                this.countToNode.delete(count);
            }
        }
    }

    dec(key) {
        let count = this.keyCount.get(key);
        this.keyCount.set(key, count - 1);
        let newCount = count - 1;

        this.countToNode.get(count).keys.delete(key);
        if (this.countToNode.get(count).keys.size === 0) {
            this._removeNode(this.countToNode.get(count));
            this.countToNode.delete(count);
        }

        if (newCount > 0) {
            if (!this.countToNode.has(newCount)) {
                let newNode = new ListNode();
                this.countToNode.set(newCount, newNode);
                this._insertNodeAfter(newNode, this.countToNode.get(count).prev);
            }
            this.countToNode.get(newCount).keys.add(key);
        } else {
            this.keyCount.delete(key);
        }
    }

    getMaxKey() {
        return this.tail.prev === this.head ? "" : Array.from(this.tail.prev.keys)[0];
    }

    getMinKey() {
        return this.head.next === this.tail ? "" : Array.from(this.head.next.keys)[0];
    }

    _removeNode(node) {
        node.prev.next = node.next;
        node.next.prev = node.prev;
    }
}

// ... (additional helper functions such as `insertNewKey`, `incrementExistingKey`, `moveToPreviousCount` would be implemented here)

// (The remaining helpers and logic can be implemented following the below pattern):
// Implement helper methods such as `insertNewKey`, `incrementExistingKey`, and `moveToPreviousCount`
// which follow the logic outlined in the provided Java code. These helpers manage the linked list
// and the nodes map, ensuring that keys are correctly incremented or decremented in counts and
// the corresponding nodes are inserted or removed as needed within the list structure.