"""
3356. Zero Array Transformation II
    You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri, vali].
    Each queries[i] represents the following action on nums:
    Decrement the value at each index in the range [li, ri] in nums by at most vali.
    The amount by which each value is decremented can be chosen independently for each index.
    A Zero Array is an array with all its elements equal to 0.
    Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.

    Example 1:
    Input: nums = [2,0,2], queries = [[0,2,1],[0,2,1],[1,1,3]]
    Output: 2
    Explanation:
    For i = 0 (l = 0, r = 2, val = 1):
    Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
    The array will become [1, 0, 1].
    For i = 1 (l = 0, r = 2, val = 1):
    Decrement values at indices [0, 1, 2] by [1, 0, 1] respectively.
    The array will become [0, 0, 0], which is a Zero Array. Therefore, the minimum value of k is 2.
"""

from typing import List
class Solution:
    def minZeroArray(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        m = len(queries)
        prefix = [0] * (n + 1)
        current = 0
        idx = 0
        for i, num in enumerate(nums):
            current += prefix[i]
            while idx < m and current < num:
                left, right, val = queries[idx]
                idx += 1
                if i < left:
                    prefix[left] += val
                elif i <= right:
                    current += val
                prefix[right + 1] -= val
            if current < num:
                return -1
        return idx