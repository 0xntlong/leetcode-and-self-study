"""
916. Word Subsets
    You are given two string arrays words1 and words2.
    A string b is a subset of string a if every letter in b occurs in a including multiplicity.
    For example, "wrr" is a subset of "warrior" but is not a subset of "world".
    A string a from words1 is universal if for every string b in words2, b is a subset of a.
    Return an array of all the universal strings in words1. You may return the answer in any order.

    Example :
    Input: words1 = ["amazon","apple","facebook","google","leetcode"], words2 = ["e","o"]
    Output: ["facebook","google","leetcode"]
"""

from typing import List
class Solution:
    def wordSubsets(self, words1: List[str], words2: List[str]) -> List[str]:
        s1 = set(words1)
        char = {}
        for word in words2:
            for j in word:
                c = word.count(j)
                if j not in char or c > char[j]:
                    char[j] = c
        for word in words1:
            for j in char:
                if word.count(j) < char[j]:
                    s1.remove(word)
                    break
        return list(s1)