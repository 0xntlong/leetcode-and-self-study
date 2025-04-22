"""
2338. Count the Number of Ideal Arrays
    You are given two integers n and maxValue, which are used to describe an ideal array.
    A 0-indexed integer array arr of length n is considered ideal if the following conditions hold:
    Every arr[i] is a value from 1 to maxValue, for 0 <= i < n.
    Every arr[i] is divisible by arr[i - 1], for 0 < i < n.
    Return the number of distinct ideal arrays of length n. Since the answer may be very large, return it modulo 109 + 7.
    Example :
    Input: n = 2, maxValue = 5
    Output: 10
    Explanation: The following are the possible ideal arrays:
    - Arrays starting with the value 1 (5 arrays): [1,1], [1,2], [1,3], [1,4], [1,5]
    - Arrays starting with the value 2 (2 arrays): [2,2], [2,4]
    - Arrays starting with the value 3 (1 array): [3,3]
    - Arrays starting with the value 4 (1 array): [4,4]
    - Arrays starting with the value 5 (1 array): [5,5]
    There are a total of 5 + 2 + 1 + 1 + 1 = 10 distinct ideal arrays.
"""


from functools import cache
from math import comb
class Solution:
    def idealArrays(self, n: int, maxValue: int) -> int:
        MOD = 10**9 + 7
        @cache
        def rec(k, val):
            if k == n:
                return comb(n - 1, k - 1)
            count = comb(n - 1, k - 1)
            
            for i in range(2, maxValue // val + 1):
                count = (count + rec(k + 1, val * i)) % MOD
            return count
        res = 0
        for i in range(1, maxValue + 1):
            res = (res + rec(1, i)) % MOD
        return res