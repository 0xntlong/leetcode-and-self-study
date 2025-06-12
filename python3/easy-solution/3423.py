"""
3423. Maximum Difference Between Adjacent Elements in a Circular Array
    Given a circular array nums, find the maximum absolute difference between adjacent elements.
    Note: In a circular array, the first and last elements are adjacent.

    Example 1:
    Input: nums = [1,2,4]
    Output: 3
    Explanation:
    Because nums is circular, nums[0] and nums[2] are adjacent. They have the maximum absolute difference of |4 - 1| = 3.
"""

from typing import List
class Solution:
    def maxAdjacentDistance(self, nums: List[int]) -> int:
        n = len(nums)
        nums.append(nums[0])
        return max(abs(nums[i] - nums[i + 1]) for i in range(n))