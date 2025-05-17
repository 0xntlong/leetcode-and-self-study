"""
75. Sort Colors
    Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
    We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
    You must solve this problem without using the library's sort function.

    Example :
    Input: nums = [2,0,2,1,1,0]
    Output: [0,0,1,1,2,2]
"""
from typing import List

class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        red, white, blue = 0, 1, 2
        left, mid, right = 0, 0, len(nums) - 1
        while mid <= right:
            i = nums[mid]
            if i == red:
                nums[left], nums[mid] = nums[mid], nums[left]
                left += 1
                mid += 1
            elif i == white:
                mid += 1
            else:
                nums[mid], nums[right] = nums[right], nums[mid]
                right -= 1
                