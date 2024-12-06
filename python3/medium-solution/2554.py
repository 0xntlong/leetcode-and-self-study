"""
2554. Maximum Number of Integers to Choose From a Range I
    You are given an integer array banned and two integers n and maxSum. You are choosing some number of integers following the below rules:
    The chosen integers have to be in the range [1, n].
    Each integer can be chosen at most once.
    The chosen integers should not be in the array banned.
    The sum of the chosen integers should not exceed maxSum.
    Return the maximum number of integers you can choose following the mentioned rules.

    Example :
    Input: banned = [1,6,5], n = 5, maxSum = 6
    Output: 2
    Explanation: You can choose the integers 2 and 4.
    2 and 4 are from the range [1, 5], both did not appear in banned, and their sum is 6, which did not exceed maxSum.
"""

from typing import List
class Solution:
    def maxCount(self, banned: List[int], n: int, maxSum: int) -> int:
        banned_set = set(banned)
        count = 0
        Sum = 0
        for i in range(1, n + 1):
            if i in banned_set:
                continue
            Sum += i
            if Sum > maxSum:
                break
            count += 1
        return count