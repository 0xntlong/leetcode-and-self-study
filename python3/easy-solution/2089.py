"""
2089. Find Target Indices After Sorting Array
    You are given a 0-indexed integer array nums and a target element target.
    A target index is an index i such that nums[i] == target.
    Return a list of the target indices of nums after sorting nums in non-decreasing order. If there are no target indices, return an empty list. The returned list must be sorted in increasing order.

    Example :
    Input: nums = [1,2,5,2,3], target = 2
    Output: [1,2]
    Explanation: After sorting, nums is [1,2,2,3,5].
    The indices where nums[i] == 2 are 1 and 2.
"""

from typing import List
class Solution:
    def targetIndices(self, nums: List[int], target: int) -> List[int]:
        nums.sort()
        idx = []
        for i in range(len(nums)):
            if nums[i] == target:
                idx.append(i)
        return idx