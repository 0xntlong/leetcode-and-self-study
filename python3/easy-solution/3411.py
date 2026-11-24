"""
3411. Maximum Subarray With Equal Products
    You are given an array of positive integers nums.
    An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:
    prod(arr) is the product of all elements of arr.
    gcd(arr) is the GCD of all elements of arr.
    lcm(arr) is the LCM of all elements of arr.
    Return the length of the longest product equivalent subarray of nums.

    Example 1:
    Input: nums = [1,2,1,2,1,1,1]
    Output: 5
    Explanation: 
    The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1, 1, 1]) = 2, gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.
"""

from typing import List
class Solution:
    def maxLength(self, nums: List[int]) -> int:
        MASKS = (0, 0, 1, 2, 1, 4, 3, 8, 1, 2, 5)

        res = min(len(nums), 2)
        window_mask = 0
        start = 0

        for end, x in enumerate(nums):
            m = MASKS[x]
            while window_mask & m:
                window_mask ^= MASKS[nums[start]]
                start += 1
            window_mask |= m
            
            curr_len = end - start + 1
            if curr_len > res:
                res = curr_len

        return res