"""
712. Minimum ASCII Delete Sum for Two Strings
    Given two strings s1 and s2, return the lowest ASCII sum of deleted characters to make two strings equal.
    Example :
    Input: s1 = "sea", s2 = "eat"
    Output: 231
    Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
    Deleting "t" from "eat" adds 116 to the sum.
    At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
"""


class Solution:
    def minimumDeleteSum(self, s1: str, s2: str) -> int:
        n1 = len(s1)
        n2 = len(s2)
        dp = [0] * (n2 + 1)
        for i in range(1, n1 + 1):
            dp_new = dp.copy()
            for j in range(1, n2 + 1):
                if s1[i - 1] == s2[j - 1]:
                    dp_new[j] = ord(s2[j - 1]) + dp[j - 1]
                else:
                    dp_new[j] = max(dp[j], dp_new[j - 1])
            dp = dp_new
        total = 0
        for c in s1:
            total += ord(c)
        for c in s2:
            total += ord(c)
        return total - 2 * dp[n2]