"""
862. Shortest Subarray with Sum at Least K
    Given an integer array nums and an integer k, return the length of the shortest non-empty subarray of nums with a sum of at least k. If there is no such subarray, return -1.
    A subarray is a contiguous part of an array.

    Example :
    Input: nums = [1], k = 1
    Output: 1
"""


from collections import deque
from typing import List
class Solution:
    def shortestSubarray(self, nums: List[int], k: int) -> int:
        n = len(nums)
        prefix = [0] * (n + 1)
        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]
        dq = deque()
        min_length = float('inf')
        for i in range(n + 1):
            while dq and prefix[i] - prefix[dq[0]] >= k:
                min_length = min(min_length, i - dq.popleft())
            while dq and prefix[i] <= prefix[dq[-1]]:
                dq.pop()
            dq.append(i)
        return min_length if min_length != float('inf') else -1