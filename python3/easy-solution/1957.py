"""
1957. Delete Characters to Make Fancy String
    A fancy string is a string where no three consecutive characters are equal.
    Given a string s, delete the minimum possible number of characters from s to make it fancy.
    Return the final string after the deletion. It can be shown that the answer will always be unique.

    Example:
    leeetcode"
    Output: "leetcode"
    Explanation:
    Remove an 'e' from the first group of 'e's to create "leetcode".
    No three consecutive characters are equal, so return "leetcode".
"""

class Solution:

# APPRAOCH 1
    def makeFancyString(self, s: str) -> str:
        result = []
        for i in s:
            if (len(result) < 2) or not (result[-1] == i and result[-2] == i):
                result.append(i)
        return "".join(result)
    
# APPROACH 2
    def makeFancyString(self, s: str) -> str:
            streak = 0
            res = "" 
            for i in range(len(s)):
                if s[i] == s[i-1]:
                    streak += 1
                else:
                    streak = 1
                if streak < 3:
                    res += s[i]
            return res