"""
3174. Clear Digits
    You are given a string s.
    Your task is to remove all digits by doing this operation repeatedly:
    Delete the first digit and the closest non-digit character to its left.
    Return the resulting string after removing all digits.

    Example :
    Input: s = "abc"
    Output: "abc"
    Explanation:
    There is no digit in the string.
"""


class Solution:
    def clearDigits(self, s: str) -> str:
        s = list(s)
        i = 0
        for j in s:
            if j.isdigit() and i > 0:
                i -= 1
            else:
                s[i] = j
                i += 1
        return "".join(s[:i])