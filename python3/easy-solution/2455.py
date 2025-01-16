"""
2455. Average Value of Even Numbers That Are Divisible by Three
    Given an integer array nums of positive integers, return the average value of all even integers that are divisible by 3.
    Note that the average of n elements is the sum of the n elements divided by n and rounded down to the nearest integer.

    Example 1:
    Input: nums = [1,3,6,10,12,15]
    Output: 9
    Explanation: 6 and 12 are even numbers that are divisible by 3. (6 + 12) / 2 = 9.
"""

from typing import List
class Solution:
    def averageValue(self, nums: List[int]) -> int:
        count = 0
        div = 0
        for i in nums:
            if i % 6 == 0:
                div += i
                count += 1
        if count == 0:
            return 0
        return div // count
