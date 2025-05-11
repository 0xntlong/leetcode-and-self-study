"""
1550. Three Consecutive Odds
    Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
    Example :
    Input: arr = [2,6,4,1]
    Output: false
    Explanation: There are no three consecutive odds.
"""

from typing import List
class Solution:
    def threeConsecutiveOdds(self, arr: List[int]) -> bool:
        if len(arr) < 3:
            return False
        for i in range(len(arr) - 2):
            if arr[i] & 1 and arr[i + 1] & 1 and arr[i + 2] & 1:
                return True
        return False