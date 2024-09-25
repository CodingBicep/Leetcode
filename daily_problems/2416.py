# 2416: Sum of prefix scores of strings

# Given: words (array) -> size n -> non empty strings
# Score: How many words starts with same prefix
# To Find: answer(array) -> Sum of scores of all non empty strings

# Example1: 
# ["abc", "ab", "bc", "b"]
# How many scores in word anc:
# prefix a, Score of a => 1(_a_bc) + 1(_a_b) = 2
# for ab => 1(_ab_c) + 1(_ab_) = 2
# for abc => 1
# Total = 2 + 2 + 1 = 5
# For word "ab" 
# Score of a => 1(_a_bc) + 1(_a_b) = 2 
# Score of ab => 1(_ab_c) + 1(_ab_) = 2  
# Total = 2 + 2 = 4
# For word "bc"
# Score of b => 1 + 1 = 2
# for bc => 1 
# Total = 3
# For word b
# Score of b = 2
# Output = [5, 4, 3, 2]


# Approach:
# Optimal approach => Prefix Tree (Trie):
# Trie (Prefix Tree) = tree like data structure, highly effective for hancling prefix related problems
# It allows us to: Insert all words and Count how many words share common prefix


# Steps:
# i. Build a Trie
# ii. Travers through the trie to calculate scores
# iii. Count how many words share common prefix (Total score)
# Code Steps:
# Start by defining trie node and trie classes
# Insert all words into a trie
# Calculate score for each word
# Return result

from typing import List



class TrieNode:
    def __init__(self):
        self.children = {}
        self.count = 0

class Trie:
    def __init__(self):
        self.root = TrieNode()
    
    def insert(self, word):
        node = self.root
        for char in word:
            if char not in node.children:
                node.children[char] = TrieNode()
            node = node.children[char]
            node.count += 1  # Increment the count for each prefix

    def get_word_score(self, word):
        node = self.root
        score = 0
        for char in word:
            if char in node.children:
                node = node.children[char]
                score += node.count  # Add the count at this node (representing the current prefix)
            else:
                break
        return score

class Solution:
    def sumPrefixScores(self, words: List[str]) -> List[int]:
        trie = Trie()
        result = []
        
        # Step 1: Insert all words into the Trie
        for word in words:
            trie.insert(word)
        
        # Step 2: For each word, calculate the sum of scores of all its prefixes
        for word in words:
            total_score = trie.get_word_score(word)
            result.append(total_score)
        
        return result
