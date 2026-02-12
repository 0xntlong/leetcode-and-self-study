"""
3713. Longest Balanced Substring I
    You are given a string s consisting of lowercase English letters.
    A substring of s is called balanced if all distinct characters in the substring appear the same number of times.
    Return the length of the longest balanced substring of s.

    Example:
    Input: s = "abbac"
    Output: 4
    Explanation:

    The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.
"""



class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        s = [ord(c) - ord('a') for c in s]
        res = 0
        for l in range(n):
            if n - l <= res:
                break
            freq = [0] * 26
            unique = maxFreq = 0
            for r in range(l, n):
                i = s[r]
                unique += freq[i] == 0
                freq[i] += 1
                maxFreq = max(maxFreq, freq[i])
                curr = r - l + 1
                if unique * maxFreq == curr:
                    res = max(res, curr)
        return res