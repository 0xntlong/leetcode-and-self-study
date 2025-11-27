"""
3381. Maximum Subarray Sum With Length Divisible by K
    You are given an array of integers nums and an integer k.
    Return the maximum sum of a subarray of nums, such that the size of the subarray is divisible by k.

    Example :
    Input: nums = [1,2], k = 1
    Output: 3
    Explanation:
    The subarray [1, 2] with sum 3 has length equal to 2 which is divisible by 1.
"""

from typing import List

class Solution:
    def maxSubarraySum(self, nums: List[int], k: int) -> int:
        min_prefix = [float('inf')] * k
        min_prefix[0] = 0
        prefix = 0
        res = float('-inf')
        for i, x in enumerate(nums, 1):
            prefix += x
            div = i % k
            res = max(res, prefix - min_prefix[div])
            if prefix < min_prefix[div]:
                min_prefix[div] = prefix
        return res