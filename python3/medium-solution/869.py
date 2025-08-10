"""
869. Reordered Power of 2
    You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
    Return true if and only if we can do this so that the resulting number is a power of two.

    Example 1:
    Input: n = 1
    Output: true
"""


class Solution:
    def reorderedPowerOf2(self, n: int) -> bool:
        s = sorted(str(n))
        for i in range(31):
            power = 1 << i
            if s == sorted(str(power)):
                return True
        return False