"""
1952. Three Divisors
    Given an integer n, return true if n has exactly three positive divisors. Otherwise, return false.
    An integer m is a divisor of n if there exists an integer k such that n = k * m.

    Example :
    Input: n = 2
    Output: false
    Explantion: 2 has only two divisors: 1 and 2.
"""

class Solution:
    def isThree(self, n: int) -> bool:
        count = 2
        for i in range(count, n):
            if n % i == 0:
                count += 1
                if count > 3:
                    return False
        return count == 3