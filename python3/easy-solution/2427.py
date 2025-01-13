"""
2427. Number of Common Factors
    Given two positive integers a and b, return the number of common factors of a and b.
    An integer x is a common factor of a and b if x divides both a and b.

    Example :
    Input: a = 12, b = 6
    Output: 4
    Explanation: The common factors of 12 and 6 are 1, 2, 3, 6.
"""


class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        common = min(a, b)
        res = 0
        for i in range(1, common + 1):
            if ( a % i == 0 and b % i == 0):
                res += 1
        return res