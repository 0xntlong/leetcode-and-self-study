"""
3754. Concatenate Non-Zero Digits and Multiply by Sum I
    You are given an integer n.
    Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.
    Let sum be the sum of digits in x.
    Return an integer representing the value of x * sum.

    Example:
    Input: n = 10203004
    Output: 12340
    Explanation:
    The non-zero digits are 1, 2, 3, and 4. Thus, x = 1234.
    The sum of digits is sum = 1 + 2 + 3 + 4 = 10.
    Therefore, the answer is x * sum = 1234 * 10 = 12340.
"""



class Solution:
    def sumAndMultiply(self, n: int) -> int:
        if n == 0:
            return 0
        arr = []
        while n:
            d = n % 10
            if d > 0:
                arr.append(d)
            n = n // 10
        s = sum(arr)
        res = 0
        for i, d in enumerate(arr):
            res += (d * 10 ** i)
        return res * s