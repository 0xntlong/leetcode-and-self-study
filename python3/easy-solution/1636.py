"""
1636. Sort Array by Increasing Frequency
    Given an array of integers nums, sort the array in increasing order based on the frequency of the values. If multiple values have the same frequency, sort them in decreasing order.
    Return the sorted array.

    Example :
    Input: nums = [1,1,2,2,2,3]
    Output: [3,1,1,2,2,2]
    Explanation: '3' has a frequency of 1, '1' has a frequency of 2, and '2' has a frequency of 3.
"""

from typing import List
class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        count: List[int] = [0 for _ in range(201)]
        for num in nums:
            count[num +100] += 1
        nums.sort(key=lambda val: (count[val + 100], -val))
        return nums