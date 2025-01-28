"""
2485. Find the Pivot Integer
    Given a positive integer n, find the pivot integer x such that:
    The sum of all elements between 1 and x inclusively equals the sum of all elements between x and n inclusively.
    Return the pivot integer x. If no such integer exists, return -1. It is guaranteed that there will be at most one pivot index for the given input.

    Example :
    Input: n = 8
    Output: 6
    Explanation: 6 is the pivot integer since: 1 + 2 + 3 + 4 + 5 + 6 = 6 + 7 + 8 = 21.
"""

from typing import List
class Solution:
    def pivotInteger(self, n: int) -> int:
        total = n * (n + 1) // 2
        for i in range(1, n + 1):
            left_sum = i * (i + 1) // 2
            if left_sum == total - left_sum + i:
                return i
        return -1