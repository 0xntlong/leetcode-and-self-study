"""
1995. Count Special Quadruplets
    Given a 0-indexed integer array nums, return the number of distinct quadruplets (a, b, c, d) such that:
    nums[a] + nums[b] + nums[c] == nums[d], and
    a < b < c < d

    Example :
    Input: nums = [1,2,3,6]
    Output: 1
    Explanation: The only quadruplet that satisfies the requirement is (0, 1, 2, 3) because 1 + 2 + 3 == 6.
"""

from typing import List
from collections import defaultdict
class Solution:
    def countQuadruplets(self, nums: List[int]) -> int:
        count = defaultdict(int)
        n = len(nums)
        res = 0
        count[nums[n - 1] - nums[n - 2]] += 1
        for b in range(n - 3, 0, -1):
            for a in range(b -1, -1, -1):
                res += count[nums[a] + nums[b]]
            for d in range(n -1, b, -1):
                count[nums[d] - nums[b]] += 1
        return res