"""
940. Distinct Subsequences II
    Given a string s, return the number of distinct non-empty subsequences of s. Since the answer may be very large, return it modulo 109 + 7.
    A subsequence of a string is a new string that is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not.
    Example :
    Input: s = "abc"
    Output: 7
    Explanation: The 7 d
"""


class Solution:
    def distinctSubseqII(self, s: str) -> int:
        MOD = 10**9 + 7
        count = [0] * 26
        total_sum = 0

        for c in s:
            total = (1 + total_sum) % MOD
            idx = ord(c) - ord('a')

            total_sum = (total_sum + total - count[idx]) % MOD
            count[idx] = total

        return total_sum