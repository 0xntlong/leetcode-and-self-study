"""
3345. Smallest Divisible Digit Product I
    You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.
    Example :
    Input: n = 10, t = 2
    Output: 10
    Explanation:
    The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.
"""


class Solution:
    def smallestNumber(self, n: int, t: int) -> int:
        for i in range(n, n + 1000):
            x = i
            temp = 1
            while x > 0:
                temp *= x % 10
                x //= 10
            if temp % t == 0:
                return i