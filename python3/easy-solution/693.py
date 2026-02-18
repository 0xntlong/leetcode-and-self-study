"""
693. Binary Number with Alternating Bits
    Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.
    Example :
    Input: n = 5
    Output: true
    Explanation: The binary representation of 5 is: 101
"""




class Solution:
    def hasAlternatingBits(self, n: int) -> bool:
        n = bin(n)[2:]
        for i in range(1, len(n)):
            if n[i - 1] == n[i]:
                return False
        return True