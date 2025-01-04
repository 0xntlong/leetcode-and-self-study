"""
1930. Unique Length-3 Palindromic Subsequences
    Given a string s, return the number of unique palindromes of length three that are a subsequence of s.
    Note that even if there are multiple ways to obtain the same subsequence, it is still only counted once.
    A palindrome is a string that reads the same forwards and backwards.
    A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.
    For example, "ace" is a subsequence of "abcde".

    Example :
    Input: s = "aabca"
    Output: 3
    Explanation: The 3 palindromic subsequences of length 3 are:
    - "aba" (subsequence of "aabca")
    - "aaa" (subsequence of "aabca")
    - "aca" (subsequence of "aabca")
"""


class Solution:
    def countPalindromicSubsequence(self, s: str) -> int:
        left = [float('inf')]*26
        right = [-1] * 26
        res = 0
        for i, char in enumerate(s):
            left[ord(char) - ord('a')] = min(left[ord(char) - ord('a')], i)
            right[ord(char) - ord('a')] = i

        for i in range(26):
            if left[i] < right[i]:
                res += len(set(s[left[i] + 1:right[i]]))
        return res