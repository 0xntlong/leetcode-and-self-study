"""
1790. Check if One String Swap Can Make Strings Equal
    You are given two strings s1 and s2 of equal length. A string swap is an operation where you choose two indices in a string (not necessarily different) and swap the characters at these indices.
    Return true if it is possible to make both strings equal by performing at most one string swap on exactly one of the strings. Otherwise, return false.

    Example :
    Input: s1 = "bank", s2 = "kanb"
    Output: true
    Explanation: For example, swap the first character with the last character of s2 to make "bank".
"""

from collections import defaultdict
from typing import List
class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        count = defaultdict(int)
        for u, v in edges:
            count[v] += 1
        champion, parentCount = 0, 0
        for i in range(n):
            if not count[i]:
                champion = i
                parentCount += 1
            if parentCount == 2:
                return -1
        return champion