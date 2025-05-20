"""
3355. Zero Array Transformation I
    You are given an integer array nums of length n and a 2D array queries, where queries[i] = [li, ri].
    For each queries[i]:
    Select a subset of indices within the range [li, ri] in nums.
    Decrement the values at the selected indices by 1.
    A Zero Array is an array where all elements are equal to 0.
    Return true if it is possible to transform nums into a Zero Array after processing all the queries sequentially, otherwise return false.

    Example :
    Input: nums = [1,0,1], queries = [[0,2]]
    Output: true
    Explanation:
    For i = 0:
    Select the subset of indices as [0, 2] and decrement the values at these indices by 1.
    The array will become [0, 0, 0], which is a Zero Array.
"""

from typing import List

class Solution:
    def isZeroArray(self, nums: List[int], queries: List[List[int]]) -> bool:
        n = len(nums)
        m = len(queries)
        freq = [0] * (n + 1)
        for l, r in queries:
            freq[l] += 1
            freq[r + 1] -= 1

        count = 0
        for i, x in enumerate(nums):
            count += freq[i]
            if x > count:
                return False
        return True