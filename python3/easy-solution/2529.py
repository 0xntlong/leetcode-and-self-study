"""
2529. Maximum Count of Positive Integer and Negative Integer
    Given an array nums sorted in non-decreasing order, return the maximum between the number of positive integers and the number of negative integers.
    In other words, if the number of positive integers in nums is pos and the number of negative integers is neg, then return the maximum of pos and neg.
    Note that 0 is neither positive nor negative.

    Example :
    Input: nums = [-2,-1,-1,1,2,3]
    Output: 3
    Explanation: There are 3 positive integers and 3 negative integers. The maximum count among them is 3.
"""

from typing import List
    
class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        pos = 0
        neg = 0
        for i in nums:
            if i > 0:
                pos += 1
            elif i < 0:
                neg += 1
            else:
                continue
        return max(pos, neg)            