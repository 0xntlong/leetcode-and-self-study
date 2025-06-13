"""
2616. Minimize the Maximum Difference of Pairs
    You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.
    Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.
    Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.

    Example :
    Input: nums = [10,1,2,7,1,3], p = 2
    Output: 1
    Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
    The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
"""

from typing import List

class Solution:
    def numsPairs(self, nums: List[int], diff: int, p: int) -> bool:
        c = 0
        i = 0
        n = len(nums)
        while i < n - 1:
            if nums[i + 1] - nums[i] <= diff:
                c += 1
                if c >= p:
                    return True
                i += 2
            else:
                i += 1
        return False

    def minimizeMax(self, nums: List[int], p: int) -> int:
        if p == 0:
            return 0
        nums.sort()
        l = 0
        r = nums[-1] - nums[0]
        ans = 0
        while l <= r:
            m = (l + r) // 2
            if self.numsPairs(nums, m, p):
                ans = m
                r = m - 1
            else:
                l = m + 1
        return ans