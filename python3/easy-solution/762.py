"""
762. Prime Number of Set Bits in Binary Representation
    Given two integers left and right, return the count of numbers in the inclusive range [left, right] having a prime number of set bits in their binary representation.
    Recall that the number of set bits an integer has is the number of 1's present when written in binary.
    For example, 21 written in binary is 10101, which has 3 set bits.

    Example :
    Input: left = 6, right = 10
    Output: 4
    Explanation:
    6  -> 110 (2 set bits, 2 is prime)
    7  -> 111 (3 set bits, 3 is prime)
    8  -> 1000 (1 set bit, 1 is not prime)
    9  -> 1001 (2 set bits, 2 is prime)
    10 -> 1010 (2 set bits, 2 is prime)
    4 numbers have a prime number of set bits.
"""
import math

class Solution:
    def countPrimeSetBits(self, left: int, right: int) -> int:
        res = 0
        for i in range(left, right + 1):
            bits = bin(i).count('1')
            if bits != 1 and math.factorial(bits - 1) % bits == bits - 1:
                res += 1
        return res