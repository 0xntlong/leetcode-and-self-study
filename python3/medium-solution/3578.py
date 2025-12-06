"""
3578. Count Partitions With Max-Min Difference at Most K
    You are given an integer array nums and an integer k. Your task is to partition nums into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most k.

    Return the total number of ways to partition nums under this condition.

    Since the answer may be too large, return it modulo 109 + 7.

    

    Example 1:

    Input: nums = [9,4,1,3,7], k = 4

    Output: 6

    Explanation:

    There are 6 valid partitions where the difference between the maximum and minimum elements in each segment is at most k = 4:

    [[9], [4], [1], [3], [7]]
    [[9], [4], [1], [3, 7]]
    [[9], [4], [1, 3], [7]]
    [[9], [4, 1], [3], [7]]
    [[9], [4, 1], [3, 7]]
    [[9], [4, 1, 3], [7]]
"""


from collections import deque
from typing import List

class Solution:
    def countPartitions(self, nums: List[int], k: int) -> int:
        n = len(nums)
        mod = 10**9 + 7
        dp = [0] * n + [1]
        maxq = deque()
        minq = deque()
        left = -1
        for i, v in enumerate(nums):
            while maxq and nums[maxq[-1]] <= v:
                maxq.pop()
            maxq.append(i)

            while minq and nums[minq[-1]] >= v:
                minq.pop()
            minq.append(i)

            while nums[minq[0]] + k < nums[maxq[0]]:
                if minq[0] < maxq[0]:
                    left = minq.popleft()
                else:
                    left = maxq.popleft()
            dp[i] = ((dp[i-1] << 1) - dp[left - 1]) % mod
        return (dp[n - 1] - dp[n - 2]) % mod