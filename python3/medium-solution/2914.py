"""
2914. Minimum Number of Changes to Make Binary String Beautiful
    You are given a 0-indexed binary string s having an even length.
    A string is beautiful if it's possible to partition it into one or more substrings such that:
    Each substring has an even length.
    Each substring contains only 1's or only 0's.
    You can change any character in s to 0 or 1.
    Return the minimum number of changes required to make the string s beautiful.

    Example :
    Input: s = "1001"
    Output: 2
    Explanation: We change s[1] to 1 and s[3] to 0 to get string "1100".
    It can be seen that the string "1100" is beautiful because we can partition it into "11|00".
    It can be proven that 2 is the minimum number of changes needed to make the string beautiful.
"""

class Solution:
    def minChanges(self, s: str) -> int:
        res = 0
        for i in range(0, len(s), 2):
            if s[i] != s[i + 1]:
                res += 1
        return res