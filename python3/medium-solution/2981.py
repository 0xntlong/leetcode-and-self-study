"""
2981. Find Longest Special Substring That Occurs Thrice I 
    You are given a string s that consists of lowercase English letters.
    A string is called special if it is made up of only a single character. For example, the string "abc" is not special, whereas the strings "ddd", "zz", and "f" are special.
    Return the length of the longest special substring of s which occurs at least thrice, or -1 if no special substring occurs at least thrice.
    A substring is a contiguous non-empty sequence of characters within a string.

    Example :
    Input: s = "aaaa"
    Output: 2
    Explanation: The longest special substring which occurs thrice is "aa": substrings "aaaa", "aaaa", and "aaaa".
    It can be shown that the maximum length achievable is 2.
"""

class Solution:
    def substring(self, s: str, n: int, x: int) -> bool:
        count = [0] * 26
        curr = 0
        for i in range(n):
            while s[curr] != s[i]:
                curr += 1
            if i - curr + 1 >= x:
                count[ord(s[i]) - ord('a')] += 1
            if count[ord(s[i]) - ord('a')] > 2:
                return True
        return False        
    def maximumLength(self, s: str) -> int:
        n = len(s)
        left, right = 1, n
        if not self.substring(s, n, left):
            return -1
        while left + 1 < right:
            mid = (left + right) // 2
            if self.substring(s, n, mid):
                left = mid
            else:
                right = mid
        return left
