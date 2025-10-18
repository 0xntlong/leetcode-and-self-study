"""
3397. Maximum Number of Distinct Elements After Operations
    You are given an integer array nums and an integer k.
    You are allowed to perform the following operation on each element of the array at most once:
    Add an integer in the range [-k, k] to the element.
    Return the maximum possible number of distinct elements in nums after performing the operations.

    Example 1:
    Input: nums = [1,2,2,3,3,4], k = 2
    Output: 6
    Explanation:
    nums changes to [-1, 0, 1, 2, 3, 4] after performing operations on the first four elements.
"""

from typing import List

class Solution:
    def maxDistinctElements(self, nums: List[int], k: int) -> int:
        nums.sort()
        n = len(nums)
        res = 0
        prev = float("-inf")
        for i in nums:
            if prev < i - k:
                prev = i - k
                res += 1
            elif prev < i + k:
                prev = prev + 1
                res += 1
        return res