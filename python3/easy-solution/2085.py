"""
2085. Count Common Words With One Occurrence
    Given two string arrays words1 and words2, return the number of strings that appear exactly once in each of the two arrays.

    Example :
    Input: words1 = ["leetcode","is","amazing","as","is"], words2 = ["amazing","leetcode","is"]
    Output: 2
    Explanation:
    - "leetcode" appears exactly once in each of the two arrays. We count this string.
    - "amazing" appears exactly once in each of the two arrays. We count this string.
    - "is" appears in each of the two arrays, but there are 2 occurrences of it in words1. We do not count this string.
    - "as" appears once in words1, but does not appear in words2. We do not count this string.
    Thus, there are 2 strings that appear exactly once in each of the two arrays.
"""

from typing import List
from collections import Counter
class Solution:
    def countWords(self, words1: List[str], words2: List[str]) -> int:
        freq = 0
        s1 = Counter(words1)
        s2 = Counter(words2)
        for i, j in s1.items():
            if i in s2 and (j == 1 and s2[i] == 1):
                freq += 1
        return freq