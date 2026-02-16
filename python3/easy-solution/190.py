"""
190. Reverse Bits
    Reverse bits of a given 32 bits signed integer.
    Example :
    Input: n = 43261596
    Output: 964176192
    Explanation:
    Integer	Binary
    43261596	00000010100101000001111010011100
    964176192	00111001011110000010100101000000
"""


class Solution:
    def reverseBits(self, n: int) -> int:
        if n == 0:
            return 0
            
        res = 0
        for i in range(32):
            res = (res << 1) | (n & 1)
            n >>= 1
        return res