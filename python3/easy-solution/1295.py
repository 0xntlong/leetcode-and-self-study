"""
1295. Find Numbers with Even Number of Digits
    Given an array nums of integers, return how many of them contain an even number of digits.

    Example:
    Input: nums = [12,345,2,6,7896]
    Output: 2
    Explanation: 
    12 contains 2 digits (even number of digits). 
    345 contains 3 digits (odd number of digits). 
    2 contains 1 digit (odd number of digits). 
    6 contains 1 digit (odd number of digits). 
    7896 contains 4 digits (even number of digits). 
    Therefore only 12 and 7896 contain an even number of digits.
"""

from typing import List
class Solution:
    def findNumbers(self, nums: List[int]) -> int:
            res = 0
            for i in range(len(nums)):
                if len(str(nums[i])) % 2 == 0:
                    res += 1
            return res
