"""
2108. Find First Palindromic String in the Array
    Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".
    A string is palindromic if it reads the same forward and backward.
    
    xample :
    Input: words = ["abc","car","ada","racecar","cool"]
    Output: "ada"
    Explanation: The first string that is palindromic is "ada".
    Note that "racecar" is also palindromic, but it is not the first.
"""

from typing import List
class Solution:
    def is_Palindrome(self, s: str) -> bool:
        return s == s[::-1]
    def firstPalindrome(self, words: List[str]) -> str:
        for word in words:
            if self.is_Palindrome(word):
                return word
        return ""