"""
1680. Concatenation of Consecutive Binary Numbers
    Given an integer n, return the decimal value of the binary string formed by concatenating the binary representations of 1 to n in order, modulo 109 + 7.

    Example :
    Input: n = 1
    Output: 1
    Explanation: "1" in binary corresponds to the decimal value 1. 
"""



class Solution:
    def concatenatedBinary(self, n: int) -> int:
        mod = 10**9 + 7
        res = 0
        for i in range(1, n + 1):
            bits = i.bit_length()
            res = ((res << bits) + i) % mod
        return res