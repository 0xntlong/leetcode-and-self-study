"""
2248. Intersection of Two Arrays
    Given a 2D integer array nums where nums[i] is a non-empty array of distinct positive integers, return the list of integers that are present in each array of nums sorted in ascending order.

    Example :
    Input: nums = [[3,1,2,4,5],[1,2,3,4],[3,4,5,6]]
    Output: [3,4]
    Explanation: 
    The only integers present in each of nums[0] = [3,1,2,4,5], nums[1] = [1,2,3,4], and nums[2] = [3,4,5,6] are 3 and 4, so we return [3,4].
"""

from typing import List
from collections import defaultdict
class Solution:
    def intersection(self, nums: List[List[int]]) -> List[int]:
        counts = defaultdict(int)
        i = 0
        my_set = set()
        while i < len(nums):
            k = 0
            for k in nums[i]:
                counts[k] += 1
            i += 1
        for key, value in counts.items():
            if value == len(nums):
                my_set.add(key)
        ans = sorted(my_set)
        return ans


        