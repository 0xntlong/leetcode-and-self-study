"""
1662. Check If Two String Arrays are Equivalent
    Given two string arrays word1 and word2, return true if the two arrays represent the same string, and false otherwise.
    A string is represented by an array if the array elements concatenated in order forms the string.

    Example :
    Input: word1 = ["ab", "c"], word2 = ["a", "bc"]
    Output: true
    Explanation:
    word1 represents string "ab" + "c" -> "abc"
    word2 represents string "a" + "bc" -> "abc"
    The strings are the same, so return true.
"""

from typing import List
class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        i, j = 0, 0
        for s in word1:
            for c in s:
                if ( i == len(word2) or word2[i][j] != c):
                    return False
                j += 1
                if (j == len(word2[i])):
                    i += 1
                    j = 0
        return i == len(word2)