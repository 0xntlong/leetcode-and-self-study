"""
1358. Number of Substrings Containing All Three Characters
    Given a string s consisting only of characters a, b and c.
    Return the number of substrings containing at least one occurrence of all these characters a, b and c.

    Example :
    Input: s = "abcabc"
    Output: 10
    Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
"""



class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        freq = [0] * 3
        left, res = 0, 0
        for i, c in enumerate(s):
            freq[ord(c) - ord('a')] += 1
            while all(freq):
                res += len(s) - i
                freq[ord(s[left]) - ord('a')] -= 1
                left += 1
        return res