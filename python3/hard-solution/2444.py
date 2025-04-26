"""
2444. Count Subarrays With Fixed Bounds
    You are given an integer array nums and two integers minK and maxK.
    A fixed-bound subarray of nums is a subarray that satisfies the following conditions:
    The minimum value in the subarray is equal to minK.
    The maximum value in the subarray is equal to maxK.
    Return the number of fixed-bound subarrays.
    A subarray is a contiguous part of an array.
    Example :
    Input: nums = [1,3,5,2,7,5], minK = 1, maxK = 5
    Output: 2
    Explanation: The fixed-bound subarrays are [1,3,5] and [1,3,5,2].
"""

from typing import List
class Solution:
    def countSubarrays(self, nums: List[int], minK: int, maxK: int) -> int:
        res = 0
        maxIndex = -1
        minIndex = -1
        i = 0
        for x, y in enumerate(nums):
            if y < minK or y > maxK:
                i = x + 1
                continue
            if y == maxK:
                maxIndex = x
            if y == minK:
                minIndex = x
            res += max((min(maxIndex, minIndex) - i + 1), 0)
        return res