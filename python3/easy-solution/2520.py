"""
2520. Count the Digits That Divide a Number
    Given an integer num, return the number of digits in num that divide num.
    An integer val divides nums if nums % val == 0.

    Example 1:
    Input: num = 7
    Output: 1
    Explanation: 7 divides itself, hence the answer is 1.
"""

from typing import List
class Solution:
    def countDigits(self, num: int) -> int:
        res = 0
        n = num
        while n > 0:
            digit = n % 10
            if digit != 0 and num % digit == 0:
                res += 1
            n //= 10
        return res