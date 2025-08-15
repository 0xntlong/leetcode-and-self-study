"""
342. Power of Four
    Given an integer n, return true if it is a power of four. Otherwise, return false.
    An integer n is a power of four, if there exists an integer x such that n == 4x.

    Example :

    Input: n = 16
    Output: true
"""


from logging import log


class Solution:
    def isPowerOfFour(self, n: int) -> bool:
        
    
        if n == 1:
            return True
        if n <= 0 or n % 4:
            return False
        
        return self.isPowerOfFour(n // 4)

        # return n > 0 and log(n, 4) % 1 == 0


        # if n < 0:
        #     return False
        # i = 0
        # while True:
        #     temp = 4 ** i
        #     if temp == n:
        #         return True
        #     elif temp > n:
        #         return False
        #     i += 1
