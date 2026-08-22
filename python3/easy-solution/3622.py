"""
3622. Check Divisibility by Digit Sum and Product
    You are given a positive integer n. Determine whether n is divisible by the sum of the following two values:
    The digit sum of n (the sum of its digits).
    The digit product of n (the product of its digits).
    Return true if n is divisible by this sum; otherwise, return false.
    Example :
    Input: n = 99
    Output: true
    Explanation:
    Since 99 is divisible by the sum (9 + 9 = 18) plus product (9 * 9 = 81) of its digits (total 99), the output is true.
"""



class Solution:
    def checkDivisibility(self, n: int) -> bool:
        s = 0
        p = 1
        for i in str(abs(n)):
            d = int(i)
            s += d
            p *= d
        if n % (s + p) == 0:
            return True
        else:
            return False