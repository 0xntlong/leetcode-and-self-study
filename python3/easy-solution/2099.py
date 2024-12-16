"""
2099. Find Subsequence of Length K With the Largest Sum
    You are given an integer array nums and an integer k. You want to find a subsequence of nums of length k that has the largest sum.
    Return any such subsequence as an integer array of length k.
    A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

    Example :
    Input: nums = [2,1,3,3], k = 2
    Output: [3,3]
    Explanation:
    The subsequence has the largest sum of 3 + 3 = 6.
"""

from typing import List
import heapq
class Solution:
    def maxSubsequence(self, nums: List[int], k: int) -> List[int]:
        freq = []
        min_heap = []
        for i, num in enumerate(nums):
            heapq.heappush(min_heap, (num, i))
            if len(min_heap) > k:
                heapq.heappop(min_heap)
        min_heap.sort(key = lambda x: x[1])
        for num, _ in min_heap:
            freq.append(num)
        return freq