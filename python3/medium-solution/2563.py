"""
2563. Count the Number of Fair Pairs
    Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
    A pair (i, j) is fair if:
    0 <= i < j < n, and
    lower <= nums[i] + nums[j] <= upper
    
    Example :
    Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
    Output: 6
    Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
"""

from typing import List
import bisect
class Solution:
    def countFairPairs(self, nums: List[int], lower: int, upper: int) -> int:
        nums.sort()
        total = 0
        for i in range(len(nums)):
            left = bisect.bisect_left(nums, lower - nums[i])
            right = min(bisect.bisect_right(nums, upper - nums[i]), i)
            total += max(0, right - left)
        return total