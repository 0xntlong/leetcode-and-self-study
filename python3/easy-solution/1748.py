"""
1748. Sum of Unique Elements
    You are given an integer array nums. The unique elements of an array are the elements that appear exactly once in the array.
    Return the sum of all the unique elements of nums.

    Example :
    Input: nums = [1,2,3,2]
    Output: 4
    Explanation: The unique elements are [1,3], and the sum is 4.
"""


from collections import Counter
from typing import List
class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        s = 0
        count = Counter(nums)
        for key, value in count.items():
            if value == 1:
                s += key
        return s