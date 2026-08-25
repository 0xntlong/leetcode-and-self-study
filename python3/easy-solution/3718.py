"""
3718. Smallest Missing Multiple of K
    Given an integer array nums and an integer k, return the smallest positive multiple of k that is missing from nums.
    A multiple of k is any positive integer divisible by k.
    Example :
    Input: nums = [8,2,3,4,6], k = 2
    Output: 10
    Explanation:
    The multiples of k = 2 are 2, 4, 6, 8, 10, 12... and the smallest multiple missing from nums is 10.
"""

from typing import List
class Solution:
    def missingMultiple(self, nums: List[int], k: int) -> int:
        hashSet = set(nums)
        i = 1 
        while True:
            if i * k not in hashSet:
                return i * k
            else:
                i += 1