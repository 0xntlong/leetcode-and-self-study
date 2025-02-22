"""
2562. Find the Array Concatenation Value
    You are given a 0-indexed integer array nums.
    The concatenation of two numbers is the number formed by concatenating their numerals.
    For example, the concatenation of 15, 49 is 1549.
    The concatenation value of nums is initially equal to 0. Perform this operation until nums becomes empty:
    If there exists more than one number in nums, pick the first element and last element in nums respectively and add the value of their concatenation to the concatenation value of nums, then delete the first and last element from nums.
    If one element exists, add its value to the concatenation value of nums, then delete it.
    Return the concatenation value of the nums.

    Example :
    Input: nums = [7,52,2,4]
    Output: 596
    Explanation: Before performing any operation, nums is [7,52,2,4] and concatenation value is 0.
    - In the first operation:
    We pick the first element, 7, and the last element, 4.
    Their concatenation is 74, and we add it to the concatenation value, so it becomes equal to 74.
    Then we delete them from nums, so nums becomes equal to [52,2].
    - In the second operation:
    We pick the first element, 52, and the last element, 2.
    Their concatenation is 522, and we add it to the concatenation value, so it becomes equal to 596.
    Then we delete them from the nums, so nums becomes empty.
    Since the concatenation value is 596 so the answer is 596.
"""

from typing import List

class Solution:
    def findTheArrayConcVal(self, nums: List[int]) -> int:
        left, right = 0, len(nums) - 1
        total = 0
        while left < right:
            total += int(str(nums[left]) + str(nums[right]))
            left += 1
            right -= 1
            
        if left == right:
            total += nums[left]
    
        return total