"""
1493. Longest Subarray of 1's After Deleting One Element
    Given a binary array nums, you should delete one element from it.
    Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

    Example :
    Input: nums = [1,1,0,1]
    Output: 3
    Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
"""

from typing import List
class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        l = 0
        res = 0
        zero = 0
        for idx, val in enumerate(nums):
            if (val == 0):
                zero += 1
            if zero > 1:
                if nums[l] == 0:
                    zero -= 1
                l += 1
            res = max(res, idx - l)
        return res