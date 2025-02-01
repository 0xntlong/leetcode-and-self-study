"""
3151. Special Array I
    An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
    You are given an array of integers nums. Return true if nums is a special array, otherwise, return false.

    Example 1:
    Input: nums = [1]
    Output: true
    Explanation:
    There is only one element. So the answer is true.
"""

from typing import List

class Solution:
    def isArraySpecial(self, nums: List[int]) -> bool:
        n = len(nums)
        if n == 1:
            return True

        prev = nums[0] & 1
        for i in range(1, n):
            x = nums[i] & 1
            if x ^ prev == 0:
                return False
            prev = x
        return True        