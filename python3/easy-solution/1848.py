"""
1848. Minimum Distance to the Target Element
    Given an integer array nums (0-indexed) and two integers target and start, find an index i such that nums[i] == target and abs(i - start) is minimized. Note that abs(x) is the absolute value of x.
    Return abs(i - start).
    It is guaranteed that target exists in nums.

    Example :
    Input: nums = [1,2,3,4,5], target = 5, start = 3
    Output: 1
    Explanation: nums[4] = 5 is the only value equal to target, so the answer is abs(4 - 3) = 1.
"""

from typing import List
class Solution:
    def getMinDistance(self, nums: List[int], target: int, start: int) -> int:
        Min = float("inf")
        for i in range(len(nums)):
            if nums[i] == target:
                Min = min(Min, abs(i - start))
        return Min