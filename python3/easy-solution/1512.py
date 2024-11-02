"""
1512. Number of Good Pairs
    Given an array of integers nums, return the number of good pairs.
    A pair (i, j) is called good if nums[i] == nums[j] and i < j.
    Example :

    Input: nums = [1,2,3,1,1,3]
    Output: 4
    Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
"""

from collections import defaultdict
from typing import List
class Solution:
    def numIdenticalPairs(self, nums: List[int]) -> int:
        ans = 0 
        count = defaultdict(int)
        for i in nums:
            ans += count[i]
            count[i] += 1
        return ans