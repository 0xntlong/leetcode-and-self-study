"""
2593. Find Score of an Array After Marking All Elemnents
    You are given an array nums consisting of positive integers.
    Starting with score = 0, apply the following algorithm:
    Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
    Add the value of the chosen integer to score.
    Mark the chosen element and its two adjacent elements if they exist.
    Repeat until all the array elements are marked.
    Return the score you get after applying the above algorithm.

    Example :
    Input: nums = [2,1,3,4,5,2]
    Output: 7
    Explanation: We mark the elements as follows:
    - 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
    - 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
    - 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
    Our score is 1 + 2 + 4 = 7.
"""

from typing import List
class Solution:
    def findScore(self, nums: List[int]) -> int:
        n = len(nums)
        Sorted = sorted((num, idx) for idx, num in enumerate(nums))
        res = 0
        for num, idx in Sorted:
            if nums[idx] != -1:
                res += num
                nums[idx] = -1
                if idx > 0:
                    nums[idx - 1] = -1
                if idx < n -1:
                    nums[idx + 1] = -1
        return res