"""
2131. Longest Palindrome by Concatenating Two Letter Words
    You are given an array of strings words. Each element of words consists of two lowercase English letters.
    Create the longest possible palindrome by selecting some elements from words and concatenating them in any order. Each element can be selected at most once.
    Return the length of the longest palindrome that you can create. If it is impossible to create any palindrome, return 0.
    A palindrome is a string that reads the same forward and backward.
    Example :
    Input: words = ["lc","cl","gg"]
    Output: 6
    Explanation: One longest palindrome is "lc" + "gg" + "cl" = "lcggcl", of length 6.
    Note that "clgglc" is another longest palindrome that can be created.
"""

from typing import List
import collections
class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        f = collections.Counter(words)
        total = 0
        center = False
        for w in list(f.keys()):
            rev = w[::-1]
            if w == rev:
                total += (f[w] // 2) * 2
                if f[w] % 2:
                    center = True
            elif w < rev:
                total += 2 * min(f[w], f[rev])
        return (total + (1 if center else 0)) * 2