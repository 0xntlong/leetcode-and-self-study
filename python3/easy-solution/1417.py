"""
1417. Reformat The String
    You are given an alphanumeric string s. (Alphanumeric string is a string consisting of lowercase English letters and digits).
    You have to find a permutation of the string where no letter is followed by another letter and no digit is followed by another digit. That is, no two adjacent characters have the same type.
    Return the reformatted string or return an empty string if it is impossible to reformat the string.

    Example :
    Input: s = "a0b1c2"
    Output: "0a1b2c"
    Explanation: No two adjacent characters have the same type in "0a1b2c". "a0b1c2", "0a1b2c", "0c2a1b" are also valid permutations.
"""


class Solution:
    def reformat(self, s: str) -> str:
        alpha_str = [char for char in s if 'a' <= char <= 'z']
        digit_str = [char for char in s if '0' <= char <= '9']
        alpha = len(alpha_str)
        digit = len(digit_str)
        if abs(alpha - digit) > 1:
            return ""
        res = []
        if alpha > digit:
            longer, shorter = alpha_str, digit_str
        else:
            longer, shorter = digit_str, alpha_str
        for i in range(len(shorter)):
            res.append(longer[i])
            res.append(shorter[i])
        if len(longer) > len(shorter):
            res.append(longer[-1])
        return "".join(res)