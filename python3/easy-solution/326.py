"""
326. Power of Three
    Given an integer n, return true if it is a power of three. Otherwise, return false.
    An integer n is a power of three, if there exists an integer x such that n == 3^x.

    Example :

    Input: n = 27
    Output: true
    Explanation: 27 = 3^3
"""



class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0:
            return False
        while n > 1:
            if n % 3 == 0:
                n = n // 3
            else:
                return False
        return True