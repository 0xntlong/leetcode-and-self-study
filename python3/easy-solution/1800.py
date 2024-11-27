"""
1800. Maximum Ascending Subarray Sum
    Given an array of positive integers nums, return the maximum possible sum of an ascending subarray in nums.
    A subarray is defined as a contiguous sequence of numbers in an array.
    A subarray [numsl, numsl+1, ..., numsr-1, numsr] is ascending if for all i where l <= i < r, numsi  < numsi+1. Note that a subarray of size 1 is ascending.
    Example :

    Input: nums = [10,20,30,5,10,50]
    Output: 65
    Explanation: [5,10,50] is the ascending subarray with the maximum sum of 65.
"""

from typing import List
class Solution:
    def maxAscendingSum(self, nums: List[int]) -> int:
        max_sum, curr = nums[0], nums[0]
        for i in range(1, len(nums)):
            if nums[i - 1] < nums[i]:
                curr += nums[i]
            else :
                max_sum = max(max_sum, curr)
                curr = nums[i]
        return max(max_sum, curr)