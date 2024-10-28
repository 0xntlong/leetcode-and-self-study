"""
1446. Consecutive Characters
    The power of the string is the maximum length of a non-empty substring that contains only one unique character.
    Given a string s, return the power of s.

    Example :
    Input: s = "leetcode"
    Output: 2
    Explanation: The substring "ee" is of length 2 with the character 'e' only.
"""

class Solution:
    def maxPower(self, s: str) -> int:
        n = len(s)
        if n == 1:
            return 1
        count = 0
        maxi = -1
        for i in range(n):
            if s[i] == s[i-1]:
                count += 1
            else :
                maxi = max(count, maxi)
                count = 1
        return max(count, maxi)
        