"""
2124. Check if All A's Appears Before All B's
    Given a string s consisting of only the characters 'a' and 'b', return true if every 'a' appears before every 'b' in the string. Otherwise, return false.

    Example :
    Input: s = "aaabbb"
    Output: true
    Explanation:
    The 'a's are at indices 0, 1, and 2, while the 'b's are at indices 3, 4, and 5.
    Hence, every 'a' appears before every 'b' and we return true.
"""


class Solution:
    def checkString(self, s: str) -> bool:
        for i in range(1, len(s)):
            if s[i - 1] == 'b' and s[i] == 'a':
                return False
        return True