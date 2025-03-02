"""
2595. Number of Even and Odd Bits
    You are given a positive integer n.
    Let even denote the number of even indices in the binary representation of n with value 1.
    Let odd denote the number of odd indices in the binary representation of n with value 1.
    Note that bits are indexed from right to left in the binary representation of a number.
    Return the array [even, odd].

    Example:
    Input: n = 50
    Output: [1,2]
    Explanation:
    The binary representation of 50 is 110010.
    It contains 1 on indices 1, 4, and 5.
"""

from typing import List
class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        res = [0, 0]
        i = 0
        while n > 0:
            if n & 1:
                res[i % 2] += 1
            n >>= 1
            i += 1
        return res