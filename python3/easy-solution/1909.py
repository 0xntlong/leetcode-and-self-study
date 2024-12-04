"""
1909. Remove One Element to Make the Array Strictly Increasing
    Given a 0-indexed integer array nums, return true if it can be made strictly increasing after removing exactly one element, or false otherwise. If the array is already strictly increasing, return true.
    The array nums is strictly increasing if nums[i - 1] < nums[i] for each index (1 <= i < nums.length).

    Example :
    Input: nums = [1,2,10,5,7]
    Output: true
    Explanation: By removing 10 at index 2 from nums, it becomes [1,2,5,7].
    [1,2,5,7] is strictly increasing, so return true.
"""

from typing import List

class Solution:
    def canBeIncreasing(self, nums: List[int]) -> bool:
        stack = []
        count = 0 
        for e in nums:
            while stack and stack[-1] >= e:
                count += 1
                stack.pop()
            stack.append(e)
        stack = []
        count2 = 0
        for i in range(len(nums) - 1, -1, -1):
            while stack and stack[-1] <= nums[i]:
                count2 += 1
                stack.pop()
            stack.append(nums[i])
        if count == 0 or count == 1 or count2 == 0 or count2 == 1:
            return True
        return False 