"""
2787. Ways to Express an Integer as Sum of Powers
    Given two positive integers n and x.
    Return the number of ways n can be expressed as the sum of the xth power of unique positive integers, in other words, the number of sets of unique integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx.
    Since the result can be very large, return it modulo 109 + 7.
    For example, if n = 160 and x = 3, one way to express n is n = 23 + 33 + 53.

    Example 1:
    Input: n = 10, x = 2
    Output: 1
    Explanation: We can express n as the following: n = 32 + 12 = 10.
    It can be shown that it is the only way to express 10 as the sum of the 2nd power of unique integers.
"""

class Solution:
    def numberOfWays(self, n: int, x: int) -> int:
        mod = 10**9 + 7
        dp = [1] + [0] * n
        i = 1
        while (v := pow(i, x)) <= n:
            for s in range(n, v - 1, -1):
                dp[s] = (dp[s] + dp[s - v])
            i += 1
        return dp[n] % mod 