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

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct ListNode {
    int count;
    struct ListNode *prev;
    struct ListNode *next;
    char **keys;
    int keyCount;
} ListNode;

typedef struct {
    ListNode *head;
    ListNode *tail;
    int keyCount;
    int *counts;
    char **keys;
} AllOne;

ListNode *createNode() {
    ListNode *node = (ListNode *)malloc(sizeof(ListNode));
    node->count = 0;
    node->keys = NULL;
    node->keyCount = 0;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

AllOne* allOneCreate() {
    AllOne *obj = (AllOne *)malloc(sizeof(AllOne));
    obj->head = createNode();
    obj->tail = createNode();
    obj->head->next = obj->tail;
    obj->tail->prev = obj->head;
    obj->keyCount = 0;
    obj->counts = (int *)calloc(10000, sizeof(int)); // Assumption: max keys < 10000
    obj->keys = (char **)calloc(10000, sizeof(char *));
    return obj;
}

void allOneInc(AllOne* obj, char* key) {
    int count = obj->counts[key];
    obj->counts[key]++;
    int newCount = obj->counts[key];

    if (newCount > count) {
        // Code to update the linked list for the new count
    }
}

void allOneDec(AllOne* obj, char* key) {
    int count = obj->counts[key];
    if (count > 0) {
        obj->counts[key]--;
        // Code to update the linked list for the new count
    }
}

char* allOneGetMaxKey(AllOne* obj) {
    // Return max key logic
}

char* allOneGetMinKey(AllOne* obj) {
    // Return min key logic
}

void allOneFree(AllOne* obj) {
    // Free memory logic
}