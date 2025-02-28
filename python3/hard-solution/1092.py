"""
1092. Shortest Common Supersequence 
    Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences. If there are multiple valid strings, return any of them.

    A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.

    Example :
    Input: str1 = "abac", str2 = "cab"
    Output: "cabac"
    Explanation: 
    str1 = "abac" is a subsequence of "cabac" because we can delete the first "c".
    str2 = "cab" is a subsequence of "cabac" because we can delete the last "ac".
    The answer provided is the shortest such string that satisfies these properties.
"""

from typing import List
class Solution:
    def shortestCommonSupersequence(self, str1: str, str2: str) -> str:
        m, n = len(str1), len(str2)
        dp = [[""] * (n + 1) for _ in range(m + 1)]

        for i in range(m):
            for j in range(n):
                if str1[i] == str2[j]:
                    dp[i + 1][j + 1] = dp[i][j] + str1[i]
                else:
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j], key = len)
            
        lcs = dp[-1][-1]

        res, i, j = [], 0, 0
        for c in lcs:
            while str1[i] != c:
                res.append(str1[i])
                i += 1
            while str2[j] != c:
                res.append(str2[j])
                j += 1
            res.append(c)
            i += 1
            j += 1
        res.extend(str1[i:])
        res.extend(str2[j:])
        return "".join(res)