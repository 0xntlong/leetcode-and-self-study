"""
1262. Greatest Sum Divisible by Three
    Given an integer array nums, return the maximum possible sum of elements of the array such that it is divisible by three.

    Example 1:
    Input: nums = [3,6,5,1,8]
    Output: 18
    Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).
"""


from typing import List

class Solution:
    def maxSumDivThree(self, nums: List[int]) -> int:
        dp = [0, 0, 0]
        for num in nums:
            for cur_max in dp[:]:
                s = cur_max + num
                if s > dp[s % 3]:
                    dp[s % 3] = s
        return dp[0]