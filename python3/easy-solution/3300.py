"""
3300. Minimum Element After Replacement With Digit Sum
    You are given an integer array nums.
    You replace each element in nums with the sum of its digits.
    Return the minimum element in nums after all replacements.

    Example :
    Input: nums = [10,12,13,14]
    Output: 1
    Explanation:
    nums becomes [1, 3, 4, 5] after all replacements, with minimum element 1.
"""

from typing import List

class Solution:
    def minElement(self, nums: List[int]) -> int:
        res = float('inf')
        for i in nums:
            curr = 0
            while i:
                curr += i % 10
                i //= 10
            res = min(res, int(curr))
        return res
        