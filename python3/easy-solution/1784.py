"""
1784. Check if Binary String Has at Most One Segment of Ones
    Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

    Example :
    Input: s = "1001"
    Output: false
    Explanation: The ones do not form a contiguous segment.
"""

class Solution:
    def checkOnesSegment(self, s: str) -> bool:
        for i in range(1, len(s)):
            if s[i - 1] == "0" and s[i] == "1":
                return False
        return True