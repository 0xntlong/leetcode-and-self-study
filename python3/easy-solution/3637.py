"""
3637. Trionic Array I
    You are given an integer array nums of length n.
    An array is trionic if there exist indices 0 < p < q < n − 1 such that:
    nums[0...p] is strictly increasing,
    nums[p...q] is strictly decreasing,
    nums[q...n − 1] is strictly increasing.
    Return true if nums is trionic, otherwise return false.

    Example :
    Input: nums = [1,3,5,4,2,6]
    Output: true
    Explanation:
    Pick p = 2, q = 4:
    nums[0...2] = [1, 3, 5] is strictly increasing (1 < 3 < 5).
    nums[2...4] = [5, 4, 2] is strictly decreasing (5 > 4 > 2).
    nums[4...5] = [2, 6] is strictly increasing (2 < 6).

"""

from typing import List

class Solution:
    def isTrionic(self, nums: List[int]) -> bool:
        n = len(nums)
        if n < 3:
            return False
        p = 0
        while p + 1 < n and nums[p] < nums[p + 1]:
            p += 1
        if p == 0 or p > n - 3:
            return False
        q = p
        while q + 1 < n and nums[q] > nums[q + 1]:
            q += 1
        if q == p or q >= n - 1:
            return False
        for i in range(q, n - 1):
            if nums[i] >= nums[i + 1]:
                return False
        return True