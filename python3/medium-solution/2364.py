"""
2364. Count Number of Bad Pairs
    You are given a 0-indexed integer array nums. A pair of indices (i, j) is a bad pair if i < j and j - i != nums[j] - nums[i].
    Return the total number of bad pairs in nums.
    Example :
    Input: nums = [4,1,3,3]
    Output: 5
    Explanation: The pair (0, 1) is a bad pair since 1 - 0 != 1 - 4.
    The pair (0, 2) is a bad pair since 2 - 0 != 3 - 4, 2 != -1.
    The pair (0, 3) is a bad pair since 3 - 0 != 3 - 4, 3 != -1.
    The pair (1, 2) is a bad pair since 2 - 1 != 3 - 1, 1 != 2.
    The pair (2, 3) is a bad pair since 3 - 2 != 3 - 3, 1 != 0.
    There are a total of 5 bad pairs, so we return 5.
"""

from typing import List
from collections import enumerate
class Solution:
    def countBadPairs(self, nums: List[int]) -> int:
        hashmap = {}
        aPair = 0
        for i, num in enumerate(nums):
            key = num - i
            aPair += hashmap.get(key, 0)
            hashmap[key] = hashmap.get(key, 0) + 1

        n = len(nums)
        return (n * (n - 1)) // 2 - aPair