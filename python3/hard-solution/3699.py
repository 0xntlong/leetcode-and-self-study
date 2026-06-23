"""
3699. Number of ZigZag Arrays I
    You are given three integers n, l, and r.
    A ZigZag array of length n is defined as follows:
    Each element lies in the range [l, r].
    No two adjacent elements are equal.
    No three consecutive elements form a strictly increasing or strictly decreasing sequence.
    Return the total number of valid ZigZag arrays.
    Since the answer may be large, return it modulo 109 + 7.
    A sequence is said to be strictly increasing if each element is strictly greater than its previous one (if exists).
    A sequence is said to be strictly decreasing if each element is strictly smaller than its previous one (if exists).

    Example :
    Input: n = 3, l = 4, r = 5
    Output: 2
    Explanation:
    There are only 2 valid ZigZag arrays of length n = 3 using values in the range [4, 5]:

    [4, 5, 4]
    [5, 4, 5]
"""



from itertools import accumulate


class Solution:
    def zigZagArrays(self, n: int, l: int, r: int) -> int:
        MOD = 10**9 + 7
        m = r - l + 1
        dp = [1] * m
        for i in range(2, n + 1):
            pref = list(accumulate(dp))
            if i % 2 == 0:
                dp = [0] + pref[:-1]
            else:
                total = pref[-1]
                dp = [0] + [(total - x) % MOD for x in pref[1:]]
    
        return (sum(dp) % MOD * 2) % MOD