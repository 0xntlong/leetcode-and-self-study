"""
2255. Count Prefixes of a Given String
    You are given a string array words and a string s, where words[i] and s comprise only of lowercase English letters.
    Return the number of strings in words that are a prefix of s.

    A prefix of a string is a substring that occurs at the beginning of the string. A substring is a contiguous sequence of characters within a string.

    Example :
    Input: words = ["a","b","c","ab","bc","abc"], s = "abc"
    Output: 3
    Explanation:
    The strings in words which are a prefix of s = "abc" are:
    "a", "ab", and "abc".
    Thus the number of strings in words which are a prefix of s is 3.
"""

from typing import List

class Solution:
    def countPrefixes(self, words: List[str], s: str) -> int:
        prefixCount = 0
        # for word in words:
        #     if word == s[:len(word)]:
        #         prefixCount += 1
        # return prefixCount
        for word in words:
            if s.startswith(word):
                prefixCount += 1
        return prefixCount