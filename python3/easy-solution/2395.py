"""
2395. Find Subarrays With Equal Sum
    Given a 0-indexed integer array nums, determine whether there exist two subarrays of length 2 with equal sum. Note that the two subarrays must begin at different indices.
    Return true if these subarrays exist, and false otherwise.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example :
    Input: nums = [4,2,4]
    Output: true
    Explanation: The subarrays with elements [4,2] and [2,4] have the same sum of 6.
"""

from typing import List
class Solution:
    def findSubarrays(self, nums: List[int]) -> bool:
        n = len(nums)
        hash_set = set()
        for i in range(n - 1):
            total = nums[i] + nums[i + 1]
            if total in hash_set:
                return True
            hash_set.add(total)
        return False
            
