"""
2057. Smallest Index With Equal Elements
    Given a 0-indexed integer array nums, return the smallest index i of nums such that i mod 10 == nums[i], or -1 if such index does not exist.
    x mod y denotes the remainder when x is divided by y.
    
    Example :
    Input: nums = [0,1,2]
    Output: 0
    Explanation: 
    i=0: 0 mod 10 = 0 == nums[0].
    i=1: 1 mod 10 = 1 == nums[1].
    i=2: 2 mod 10 = 2 == nums[2].
    All indices have i mod 10 == nums[i], so we return the smallest index 0.
"""

from typing import List
class Solution:
    def smallestEqual(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            if i % 10 == nums[i]:
                return i
        return -1