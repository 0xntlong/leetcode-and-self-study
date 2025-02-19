"""
2544. Alternating Digit Sum
    You are given a positive integer n. Each digit of n has a sign according to the following rules:
    The most significant digit is assigned a positive sign.
    Each other digit has an opposite sign to its adjacent digits.
    Return the sum of all digits with their corresponding sign.

    Example :
    Input: n = 521
    Output: 4
    Explanation: (+5) + (-2) + (+1) = 4.
"""


class Solution:
    def alternateDigitSum(self, n: int) -> int:
        nums = str(n)
        res, sign = 0, 1
        for i in nums:
            res += int(i) * sign
            sign *= -1
        return res