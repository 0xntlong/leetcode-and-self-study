"""
3517. Smallest Palindromic Rearrangement I
    You are given a palindromic string s.
    Return the lexicographically smallest palindromic permutation of s.

    Example 1:
    Input: s = "z"
    Output: "z"
    Explanation:
    A string of only one character is already the lexicographically smallest palindrome.
"""



from collections import Counter


class Solution:
    def smallestPalindrome(self, s: str) -> str:
        count = Counter(s)
        left = []
        mid = ""
        for c in sorted(count):
            left.append(c * (count[c] // 2))
            if count[c] % 2:
                mid = c
        
        left = "".join(left)
        return left + mid + left[::-1]