"""
3346. Maximum Frequency of an Element After Performing Operations I
    You are given an integer array nums and two integers k and numOperations.
    You must perform an operation numOperations times on nums, where in each operation you:
    Select an index i that was not selected in any previous operations.
    Add an integer in the range [-k, k] to nums[i].
    Return the maximum possible frequency of any element in nums after performing the operations.

    Example :
    Input: nums = [1,4,5], k = 1, numOperations = 2
    Output: 2
    Explanation:
    We can achieve a maximum frequency of two by:
    Adding 0 to nums[1]. nums becomes [1, 4, 5].
    Adding -1 to nums[2]. nums becomes [1, 4, 4].
"""

from typing import List


class Solution:
    def maxFrequency(self, nums: List[int], k: int, numOperations: int) -> int:
        M = max(nums)
        dp = [0] * (M + 1)
        prev = ans = 0
        for i in nums:
            dp[i] += 1
        curr = sum(dp[:k])

        for i in range(M + 1):
            curr -= dp[i]
            if i + k <= M:
                curr += dp[i + k]
            if i > 0:
                prev += dp[i - 1]
            if i > k + 1:
                prev -= dp[i - k - 1]
            ans = max(ans, dp[i] + min(numOperations, prev + curr))
        return ans