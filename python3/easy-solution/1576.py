"""
1576. Replace All ?'s to Avoid Consecutive Repeating Characters
    Given a string s containing only lowercase English letters and the '?' character, convert all the '?' characters into lowercase letters such that the final string does not contain any consecutive repeating characters. You cannot modify the non '?' characters.
    It is guaranteed that there are no consecutive repeating characters in the given string except for '?'.
    Return the final string after all the conversions (possibly zero) have been made. If there is more than one solution, return any of them. It can be shown that an answer is always possible with the given constraints.

    Example 1:
    Input: s = "?zs"
    Output: "azs"
    Explanation: There are 25 solutions for this problem. From "azs" to "yzs", all are valid. Only "z" is an invalid modification as the string will consist of consecutive repeating characters in "zzs".
"""

class Solution:
    def modifyString(self, s: str) -> str:
        n = len(s)
        if n == 1 and s[0] == '?':
            return 'a'
        s = list(s)
        for i in range(n):
            if s[i] == '?':
                for c in 'abc':
                    if (i > 0 and s[i-1] == c) or ( i < n - 1 and s[i +1] == c):
                        continue
                    s[i] = c
                    break
        return ''.join(s)