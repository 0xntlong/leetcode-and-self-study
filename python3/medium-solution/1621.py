"""
1621. Number of Sets of K Non-Overlapping Line Segments
    Given n points on a 1-D plane, where the ith point (from 0 to n-1) is at x = i, find the number of ways we can draw exactly k non-overlapping line segments such that each segment covers two or more points. The endpoints of each segment must have integral coordinates. The k line segments do not have to cover all n points, and they are allowed to share endpoints.
    Return the number of ways we can draw k non-overlapping line segments. Since this number can be huge, return it modulo 109 + 7.

    Example :
    Input: n = 4, k = 2
    Output: 5
    Explanation: The two line segments are shown in red and blue.
    The image above shows the 5 different ways {(0,2),(2,3)}, {(0,1),(1,3)}, {(0,1),(2,3)}, {(1,2),(2,3)}, {(0,1),(1,2)}.
"""




class Solution:
    def numberOfSets(self, n: int, k: int) -> int:
        mod = 10**9 + 7

        dp = [1] * n
        prefix_sums = [0] * (n + 1)

        for j in range(n):
            prefix_sums[j + 1] = (prefix_sums[j] + dp[j]) % mod

        for _ in range(k):
            dp[0] = 0

            for j in range(1, n):
                dp[j] = (dp[j - 1] + prefix_sums[j]) % mod

            prefix_sums[0] = 0

            for j in range(n):
                prefix_sums[j + 1] = (prefix_sums[j] + dp[j]) % mod

        return dp[n - 1]