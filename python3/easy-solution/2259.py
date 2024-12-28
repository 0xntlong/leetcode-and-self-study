"""
2259. Remove Digit From Number ti Maximize Result
    You are given a string number representing a positive integer and a character digit.
    Return the resulting string after removing exactly one occurrence of digit from number such that the value of the resulting string in decimal form is maximized. The test cases are generated such that digit occurs at least once in number.

    Example :
    Input: number = "123", digit = "3"
    Output: "12"
    Explanation: There is only one '3' in "123". After removing '3', the result is "12".
"""

from typing import List
class Solution:
    def removeDigit(self, number: str, digit: str) -> str:
        n = len(number)
        temp = ""
        for i in range(n):
            if number[i] == digit:
                res = number[:i] + number[i + 1:]
                if temp < res:
                    temp = res
        return temp