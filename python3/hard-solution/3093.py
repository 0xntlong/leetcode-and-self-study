"""
3093. Longest Common Suffix Queries
    You are given two arrays of strings wordsContainer and wordsQuery.
    For each wordsQuery[i], you need to find a string from wordsContainer that has the longest common suffix with wordsQuery[i]. If there are two or more strings in wordsContainer that share the longest common suffix, find the string that is the smallest in length. If there are two or more such strings that have the same smallest length, find the one that occurred earlier in wordsContainer.
    Return an array of integers ans, where ans[i] is the index of the string in wordsContainer that has the longest common suffix with wordsQuery[i].
    
    Example :
    Input: wordsContainer = ["abcd","bcd","xbcd"], wordsQuery = ["cd","bcd","xyz"]
    Output: [1,1,1]
    Explanation:

    Let's look at each wordsQuery[i] separately:

    For wordsQuery[0] = "cd", strings from wordsContainer that share the longest common suffix "cd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
    For wordsQuery[1] = "bcd", strings from wordsContainer that share the longest common suffix "bcd" are at indices 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
    For wordsQuery[2] = "xyz", there is no string from wordsContainer that shares a common suffix. Hence the longest common suffix is "", that is shared with strings at index 0, 1, and 2. Among these, the answer is the string at index 1 because it has the shortest length of 3.
"""

from typing import List

class TrieNode:
    def __init__(self):
        self.chars = {}
        self.len_word = 0
        self.best = float("inf")
class Trie:
    def __init__(self):
        self.root = TrieNode()
    def insert(self, idx, word):
        curr = self.root
        for c in reversed(word):
            if c not in curr.chars:
                curr.chars[c] = TrieNode()
            curr = curr.chars[c]
            if curr.best == float("inf") or curr.len_word > len(word):
                curr.best = idx
                curr.len_word = len(word)
    def search(self, word):
        curr = self.root
        idx = -1
        for c in reversed(word):
            if c not in curr.chars:
                break
            curr = curr.chars[c]
            idx = curr.best
        return idx

class Solution:
    def stringIndices(self, wordsContainer: List[str], wordsQuery: List[str]) -> List[int]:
        trie = Trie()
        min_len_idx = 0
        for i, word in enumerate(wordsContainer):
            trie.insert(i, word)
            if len(wordsContainer[min_len_idx]) > len(word):
                min_len_idx = i

        ans = []
        for word in wordsQuery:
            idx = trie.search(word)
            if idx == -1:
                ans.append(min_len_idx)
            else:
                ans.append(idx)

        return ans