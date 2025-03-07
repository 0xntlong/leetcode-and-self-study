"""
2523. Closest Prime Numbers in Range
    Given two positive integers left and right, find the two integers num1 and num2 such that:
    left <= num1 < num2 <= right .
    Both num1 and num2 are prime numbers.
    num2 - num1 is the minimum amongst all other pairs satisfying the above conditions.
    Return the positive integer array ans = [num1, num2]. If there are multiple pairs satisfying these conditions, return the one with the smallest num1 value. If no such numbers exist, return [-1, -1].

    Example :
    Input: left = 10, right = 19
    Output: [11,13]
    Explanation: The prime numbers between 10 and 19 are 11, 13, 17, and 19.
    The closest gap between any pair is 2, which can be achieved by [11,13] or [17,19].
    Since 11 is smaller than 17, we return the first pair.
"""

from typing import List
from math import sqrt

class Solution:
    def closestPrimes(self, left: int, right: int) -> List[int]:
        def isPrime(n : int) -> bool:
            if n <= 1:
                return False
            if n == 2:
                return True
            
            for i in range(2, int(sqrt(n)) + 1):
                if n % i == 0:
                    return False
            return True
        res = []
        prime = None

        for i in range(left, right + 1):
            if not isPrime(i):
                continue
            if prime is None:
                prime = i
                continue
            diff = i - prime
            if diff <= 2:
                return [prime, i]
            if not res or diff < res[1] - res[0]:
                res = [prime, i]
            prime = i
        return res or [-1, -1]