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

#include <unordered_map>
#include <unordered_set>
#include <string>

class Node {
public:
    Node *prev; // Pointer to the previous node in the doubly linked list
    Node *next; // Pointer to the next node in the doubly linked list
    int count; // Count of occurrences for this node
    std::unordered_set<std::string> keys; // Set of keys with this occurrence count

    // Constructor for sentinel node
    Node() : prev(nullptr), next(nullptr), count(0) {}

    // Constructor for actual nodes with a given key and count
    Node(const std::string& key, int count) : prev(nullptr), next(nullptr), count(count) {
        keys.insert(key);
    }

    // Method to insert a node after this node
    Node* insert(Node* node) {
        node->prev = this;
        node->next = this->next;
        this->next->prev = node;
        this->next = node;
        return node;
    }

    // Remove the node from the doubly linked list
    void remove() {
        this->prev->next = this->next;
        this->next->prev = this->prev;
    }
};

class AllOne {
private:
    Node root; // Sentinel node to mark the beginning and end of the doubly linked list
    std::unordered_map<std::string, Node*> nodes; // Mapping from keys to their corresponding nodes

public:
    AllOne() {
        // Initialize the doubly linked list with the sentinel node linking to itself
        root.next = &root;
        root.prev = &root;
    }

    void inc(const std::string& key) {
        // Increase the count for the key
        if (nodes.find(key) == nodes.end()) {
            // If key is new, insert it into the list
            if (root.next == &root || root.next->count > 1) {
                nodes[key] = root.insert(new Node(key, 1));
            } else {
                root.next->keys.insert(key);
                nodes[key] = root.next;
            }
        } else {
            // If the key already exists, move it to a new or next existing Node
            Node *current = nodes[key];
            Node *next = current->next;
            if (next == &root || next->count > current->count + 1) {
                nodes[key] = current->insert(new Node(key, current->count + 1));
            } else {
                next->keys.insert(key);
                nodes[key] = next;
            }
            // Remove the key from the current Node and delete the Node if it's empty
            current->keys.erase(key);
            if (current->keys.empty()) {
                current->remove();
                delete current; // C++ requires explicit deletion
            }
        }
    }

    void dec(const std::string& key) {
        auto it = nodes.find(key);
        if (it == nodes.end()) return;
        Node *current = it->second;
        if (current->count == 1) {
            // Remove the key completely if the count is 1
            nodes.erase(key);
        } else {
            // Move the key to previous Node or create a new Node
            Node *prev = current->prev;
            if (prev == &root || prev->count < current->count - 1) {
                nodes[key] = prev->insert(new Node(key, current->count - 1));
            } else {
                prev->keys.insert(key);
                nodes[key] = prev;
            }
        }
        // Remove the key from the current Node and delete the Node if empty
        current->keys.erase(key);
        if (current->keys.empty()) {
            current->remove();
            delete current; // C++ requires explicit deletion
        }
    }

    std::string getMaxKey() {
        // Return a key with the maximum count
        if (root.prev == &root) return ""; // Handle case with no keys
        return *root.prev->keys.begin();
    }

    std::string getMinKey() {
        // Return a key with the minimum count
        if (root.next == &root) return ""; // Handle case with no keys
        return *root.next->keys.begin();
    }
};