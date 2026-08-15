"""
3702. Longest Subsequence With Non-Zero Bitwise XOR
    You are given an integer array nums.
    Return the length of the longest subsequence in nums whose bitwise XOR is non-zero. If no such subsequence exists, return 0.
    Example :
    Input: nums = [1,2,3]
    Output: 2
    Explanation:
    One longest subsequence is [2, 3]. The bitwise XOR is computed as 2 XOR 3 = 1, which is non-zero.
"""

from typing import List
class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        n = len(nums)
        if n * [0] == nums:
            return 0
        x = 0
        for i in nums:
            x ^= i

        return n if x else n - 1