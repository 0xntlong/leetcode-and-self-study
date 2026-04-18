"""
3783. Mirror Distance of an Integer
    You are given an integer n.
    Define its mirror distance as: abs(n - reverse(n)) where reverse(n) is the integer formed by reversing the digits of n.
    Return an integer denoting the mirror distance of n.
    abs(x) denotes the absolute value of x.

    Example :
    Input: n = 25
    Output: 27
    Explanation:
    reverse(25) = 52.
    Thus, the answer is abs(25 - 52) = 27.
"""


class Solution:
    def mirrorDistance(self, n: int) -> int:
        reversion = 0
        x = n
        while x > 0:
            x ,r = divmod(x, 10)
            reversion = 10 * reversion + r
        return abs(reversion - n)
        """
        reversion = 0
        x = n
        while n > 0:
            dist = n % 10
            reversion = reversion * 10 + dist
            n = n // 10
        return abs(reversion - x)
        """