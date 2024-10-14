"""
This file is a minimal set of EASY solutions to leetcode problems in Python3.
No algorithms or reasoning are provided to save space.
For more details, readers are suggested to explore on their own or search on Threads platform : leetcodedaybyday . Thanks for reading.
"""

class Solution:
    """
    1. Two Sum
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
    You can return the answer in any order.
    
    Example 1:
    Input: nums = [2,7,11,15], target = 9
    Output: [0,1]
    Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
    """
    def twoSum (self, nums, target):
        num_dict = {} 
        for i, num in enumerate(nums):
            complement = target - num
            if complement in num_dict:
                return [num_dict[complement], i]
            num_dict[num] = i 
        return []
    
    """
    9. Palindrome Number
    Given an integer x, return true if x is a palindrome , and false otherwise.

    Example 1:
    Input: x = 121
    Output: true
    Explanation: 121 reads as 121 from left to right and from right to left.
    """
    def isPalindrome(self, x: int) -> bool:
        if x < 0:
            return False
        reversed_num = 0 
        temp = x 
        while temp != 0:
            digit = temp % 10 
            reversed_num = reversed_num * 10 + digit 
            temp //= 10 
        return reversed_num == x