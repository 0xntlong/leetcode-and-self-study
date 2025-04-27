"""
3392. Count Subarrays of Length Three With a Condition
    Given an integer array nums, return the number of subarrays of length 3 such that the sum of the first and third numbers equals exactly half of the second number.
    Example :
    Input: nums = [1,2,1,4,1]
    Output: 1
    Explanation:
    Only the subarray [1,4,1] contains exactly 3 elements where the sum of the first and third numbers equals half the middle number.
"""
from typing import List
class Solution:
    def countSubarrays(self, nums: List[int]) -> int:
        n = len(nums)
        count = 0
        for i in range(1, n - 1):
            if 2 * (nums[i - 1] + nums[i + 1]) == nums[i]:
                count += 1
        return count

