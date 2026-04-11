"""
3741. Minimum Distance Between Three Equal Elements II
    You are given an integer array nums.
    A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].
    The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.
    Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.

    Example :
    Input: nums = [1,2,1,1,3]
    Output: 6
    Explanation:
    The minimum distance is achieved by the good tuple (0, 2, 3).
    (0, 2, 3) is a good tuple because nums[0] == nums[2] == nums[3] == 1. Its distance is abs(0 - 2) + abs(2 - 3) + abs(3 - 0) = 2 + 1 + 3 = 6.
"""



import math
from typing import List
    


class Solution:
    def minimumDistance(self, nums: List[int]) -> int:
        n = len(nums)
        min_len = n + 1
        last = [-1] * min_len
        second = [-1] * min_len
        min_dist = math.inf
        for i, num in enumerate(nums):
            if second[num] != -1:
                dist = i - second[num]
                if min_dist > dist:
                    min_dist = dist
            second[num] = last[num]
            last[num] = i
        if min_dist == math.inf:
            return -1
        return 2 * min_dist