"""
594. Longest Harmonious Subsequence
    We define a harmonious array as an array where the difference between its maximum value and its minimum value is exactly 1.
    Given an integer array nums, return the length of its longest harmonious subsequence among all its possible subsequences.

    Example :
    Input: nums = [1,3,2,2,5,2,3,7]
    Output: 5
    Explanation:
    The longest harmonious subsequence is [3,2,2,2,3].
"""

from collections import Counter
from typing import List
class Solution:
    def findLHS(self, nums: List[int]) -> int:
        count = Counter(nums)
        res = 0
        for i in count:
            if i + 1 in count:
                res = max(res, count[i] + count[i + 1])
        return res