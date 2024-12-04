"""
1897. Redistribute Characters to Make All Strings Equal
    You are given an array of strings words (0-indexed).
    In one operation, pick two distinct indices i and j, where words[i] is a non-empty string, and move any character from words[i] to any position in words[j].
    Return true if you can make every string in words equal using any number of operations, and false otherwise.

    Example :
    Input: words = ["abc","aabc","bc"]
    Output: true
    Explanation: Move the first 'a' in words[1] to the front of words[2],
    to make words[1] = "abc" and words[2] = "abc".
    All the strings are now equal to "abc", so return true.
"""

from typing import List
class Solution:
    def makeEqual(self, words: List[str]) -> bool:
        freq = [0] * 26
        for word in words:
            for c in word:
                freq[ord(c) - ord('a')] += 1

        size = len(words)
        for idx in range(26):
            if freq[idx] and freq[idx] % size != 0:
                return False
        return True
