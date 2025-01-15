"""
2441. Largest Positive Interger That Exitsts Withs Its Nagative 
    Given an integer array nums that does not contain any zeros, find the largest positive integer k such that -k also exists in the array.
    Return the positive integer k. If there is no such integer, return -1.

    Example :
    Input: nums = [-1,2,-3,3]
    Output: 3
    Explanation: 3 is the only valid k we can find in the array.

"""

from typing import List
class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        hash_set = set()
        
        for i in nums:
            if i < 0:
                hash_set.add(-i)
        max_k = -1
        for i in nums:
            if i > max_k and i in hash_set:
                max_k = i
        
        return max_k