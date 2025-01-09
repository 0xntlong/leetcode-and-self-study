"""
2404. Most Frequent Even Element
    Given an integer array nums, return the most frequent even element.
    If there is a tie, return the smallest one. If there is no such element, return -1.

    Example :
    Input: nums = [0,1,2,2,4,4,1]
    Output: 2
    Explanation:
    The even elements are 0, 2, and 4. Of these, 2 and 4 appear the most.
    We return the smallest one, which is 2.
"""
from typing import List

class Solution:
    def mostFrequentEven(self, nums: List[int]) -> int:
        freq = {}
        for i in nums:
            if i % 2 == 0:
                if i in freq:
                    freq[i] += 1
                else:
                    freq[i] = 1
        count = 0
        res = -1
        for i in freq:
            if freq[i] > count:
                count = freq[i]
                res = i
            elif freq[i] == count:
                if res > i:
                    res = i
        return res