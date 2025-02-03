"""
3105. Longest Strictly Increasing or Strictly Decreasing Subarray
    You are given an array of integers nums. Return the length of the longest 
    subarray of nums which is either strictly increasing or strictly decreasing
    
    Example 1:
    Input: nums = [1,4,3,3,2]
    Output: 2
    Explanation:
    The strictly increasing subarrays of nums are [1], [2], [3], [3], [4], and [1,4].
    The strictly decreasing subarrays of nums are [1], [2], [3], [3], [4], [3,2], and [4,3].
    Hence, we return 2.
"""

from typing import List
class Solution:
    def longestMonotonicSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        inc, dec = 1, 1
        if n == 1:
            return 1
        for i in range(1, n):
            if nums[i] > nums[i - 1]:
                inc += 1
                dec = 1
            elif nums[i] < nums[i - 1]:
                inc = 1
                dec += 1
            else :
                inc = dec = 1
            res = max(res, inc, dec)
        return res
