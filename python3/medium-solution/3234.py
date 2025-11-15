"""
3234. Count the Number of Substrings With Dominant Ones
    You are given a binary string s.
    Return the number of substrings with dominant ones.
    A string has dominant ones if the number of ones in the string is greater than or equal to the square of the number of zeros in the string.

    Example 1:
    Input: s = "00011"
    Output: 5
    Explanation:
    The substrings with dominant ones are shown in the table below.
    i	j	s[i..j]	Number of Zeros	Number of Ones
    3	3	1	0	1
    4	4	1	0	1
    2	3	01	1	1
    3	4	11	0	2
    2	4	011	1	2
"""


class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        n = len(s)
        dp = [-1] * (n + 1)
        for i in range(n):
            if i == 0 or s[i - 1] == '0':
                dp[i + 1] = i
            else:
                dp[i + 1] = dp[i]
        res = 0
        for i in range(1, n + 1):
            cnt0 = 1 if s[i - 1] == '0' else 0
            j = i
            while j > 0 and cnt0 * cnt0 <= n:
                cnt1 = (i - dp[j]) - cnt0
                if cnt0 * cnt0 <= cnt1:
                    res += min(j - dp[j], cnt1 - cnt0 * cnt0 + 1)
                j = dp[j]
                cnt0 += 1
        return res