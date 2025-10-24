"""
2048. Next Greater Numerically Balanced Number
    An integer x is numerically balanced if for every digit d in the number x, there are exactly d occurrences of that digit in x.
    Given an integer n, return the smallest numerically balanced number strictly greater than n.

    Example :
    Input: n = 1
    Output: 22
    Explanation: 
    22 is numerically balanced since:
    - The digit 2 occurs 2 times. 
    It is also the smallest numerically balanced number strictly greater than 1.
"""


from collections import Counter

class Solution:
    def balance(self, n):
        freq = Counter(str(n))
        for k, v in freq.items():
            if (v != int(k)):
                return False
        return True

    def nextBeautifulNumber(self, n: int) -> int:
        n += 1
        while (not self.balance(n)):
            n += 1
        return n