"""
2535. Difference Between Element Sum and Digit Sum of an Array
    You are given a positive integer array nums.
    The element sum is the sum of all the elements in nums.
    The digit sum is the sum of all the digits (not necessarily distinct) that appear in nums.
    Return the absolute difference between the element sum and digit sum of nums.
    Note that the absolute difference between two integers x and y is defined as |x - y|.

    Example :
    Input: nums = [1,15,6,3]
    Output: 9
    Explanation: 
    The element sum of nums is 1 + 15 + 6 + 3 = 25.
    The digit sum of nums is 1 + 1 + 5 + 6 + 3 = 16.
    The absolute difference between the element sum and digit sum is |25 - 16| = 9.
"""

from typing import List

class Solution:
    def differenceOfSum(self, nums: List[int]) -> int:
        element = 0
        digit = 0
        for num in nums:
            element += num
            while num > 0:
                digit  += num % 10
                num //= 10
        return abs(element - digit)