"""
2472. Maximum Number of Non-overlapping Palindrome Substrings
    You are given a string s and a positive integer k.
    Select a set of non-overlapping substrings from the string s that satisfy the following conditions:
    The length of each substring is at least k.
    Each substring is a palindrome.
    Return the maximum number of substrings in an optimal selection.
    A substring is a contiguous sequence of characters within a string.
    Example :
    Input: s = "abaccdbbd", k = 3
    Output: 2
    Explanation: We can select the substrings underlined in s = "abaccdbbd". Both "aba" and "dbbd" are palindromes and have a length of at least k = 3.
    It can be shown that we cannot find a selection with more than two valid substrings.
"""



class Solution:
    def maxPalindromes(self, s: str, k: int) -> int:
        n = len(s)
        count = 0
        last_end = 0

        def is_palindrome(left, right):
            while left < right:
                if s[left] != s[right]:
                    return False
                left += 1
                right -= 1
            return True

        for right in range(k - 1, n):
            left = right - k + 1

            add = (
                (left >= last_end and is_palindrome(left, right)) or
                (left > last_end and is_palindrome(left - 1, right))
            )

            if add:
                count += 1
                last_end = right + 1

        return count