"""
9. Palindrome Number
    Given an integer x, return true if x is a palindrome , and false otherwise.

    Example:
    Input: x = 121
    Output: true
    Explanation: 121 reads as 121 from left to right and from right to left.
"""

class Solution:
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