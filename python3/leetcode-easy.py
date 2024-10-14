"""
This file is a minimal set of EASY solutions to leetcode problems in Python3.
No algorithms or reasoning are provided to save space.
For more details, readers are suggested to explore on their own or search on Threads platform : leetcodedaybyday . Thanks for reading.
"""
from typing import List

class Solution:
    """
    1. Two Sum
    Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
    You may assume that each input would have exactly one solution, and you may not use the same element twice.
    You can return the answer in any order.
    
    Example:
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

    Example:
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
    
    """
    13. Roman to Integer
    Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
    Symbol       Value
    I             1
    V             5
    X             10
    L             50
    C             100
    D             500
    M             1000
    For example, 2 is written as II in Roman numeral, just two ones added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
    Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
    I can be placed before V (5) and X (10) to make 4 and 9. 
    X can be placed before L (50) and C (100) to make 40 and 90. 
    C can be placed before D (500) and M (1000) to make 400 and 900.
    Given a roman numeral, convert it to an integer.

    Example 1:
    Input: s = "III"
    Output: 3
    Explanation: III = 3.
    """
    def romanToInt(self, s: str) -> int:
        n = {
            'I': 1,
            'V': 5,
            'X': 10,
            'L': 50,
            'C': 100,
            'D': 500,
            'M': 1000
        }
        ans = 0 
        
        for i in range(len(s)):
            if i < len(s) - 1 and n[s[i]] < n[s[i+1]]:
                ans -= n[s[i]]
            else:
                ans += n[s[i]]
        return ans
    
    """
    14. Longest Common Prefix
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".
    
    Example:
    Input: strs = ["flower","flow","flight"]
    Output: "fl"
    """
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs :
            return ""
        strs.sort()
        ans = ""
        first = strs[0]
        last = strs[-1]
        for i in range(min(len(first), len(last))):
            if(first[i]!=last[i]):
                return ans
            ans += first[i]
        return ans
    
    """
    20. Valid Parentheses
    Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
    An input string is valid if:
    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
    
    Example:
    Input: s = "()"
    Output: true
    """
    def isValid(self, s: str) -> bool:
        sym = []
        if(s[0]==')' or s[0]==']' or s[0]=='}'):
            return False
        for i in s:
            if (i=='(' or i=='[' or i=='{'):
                sym.append(i)
            elif(len(sym)!= 0 and (sym[-1]=='(' or sym[-1]=='[' or sym[-1]=='{')):
                if((i==')' and sym[-1]=='(') or (i==']' and sym[-1]=='[') or (i=='}' and sym[-1]=='{')):
                    sym.pop()
                    
                else:
                     return False
            else:
                return False
        if(len(sym)==0):
            return True
        return False