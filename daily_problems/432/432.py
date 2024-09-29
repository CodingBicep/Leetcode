# Question:
# 432. All O`one Data Structure


# Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

# Implement the AllOne class:

# AllOne() Initializes the object of the data structure.
# inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
# dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. 
# It is guaranteed that key exists in the data structure before the decrement.
# getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
# getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
# Note that each function must run in O(1) average time complexity.
#
# Example 1:
#
# Input
# ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
# [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
#
# Output
# [null, null, null, "hello", "hello", null, "hello", "leet"]
#
# Explanation
# AllOne allOne = new AllOne();
# allOne.inc("hello");
# allOne.inc("hello");
# allOne.getMaxKey();  # return "hello"
# allOne.getMinKey();  # return "hello"
# allOne.inc("leet");
# allOne.getMaxKey();  # return "hello"
# allOne.getMinKey();  # return "leet"

class AllOne:

    def __init__(self):
       
        self.d={}
       
        self.op=0
       
        self.res=""

    def inc(self, key: str) -> None:
      
        self.op=0
        if (key in self.d):
            self.d[key]+=1
        else:
            self.d[key]=1
        return None
    def dec(self, key: str) -> None:
     
        self.op=0
        if (self.d[key]>1):
            self.d[key]-=1
        else:
            del self.d[key]
        return None

    def getMaxKey(self) -> str:
       
        if (self.op==1):
            return self.res
        self.op=1
        if (self.d):
            a=list(self.d.values())[0]
            b=list(self.d.keys())[0]
            for i in self.d.keys():
                if (self.d[i]>a):
                    a=self.d[i]
                    b=i
            self.res=b
            return b
        self.res=""
        return ""

    def getMinKey(self) -> str:
       
        if (self.op==2):
            return self.res
        self.op=2
        if (self.d):
            a=list(self.d.values())[0]
            b=list(self.d.keys())[0]
            for i in self.d.keys():
                if (self.d[i]<a):
                    a=self.d[i]
                    b=i
            self.res=b
            return b
        self.res=""
        return ""


# Your AllOne object will be instantiated and called as such:
# obj = AllOne()
# obj.inc(key)
# obj.dec(key)
# param_3 = obj.getMaxKey()
# param_4 = obj.getMinKey()