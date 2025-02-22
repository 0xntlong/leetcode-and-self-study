"""
1903. Largest Odd Number in String
    You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
    A substring is a contiguous sequence of characters within a string.

    Example :
    Input: num = "52"
    Output: "5"
    Explanation: The only non-empty substrings are "5", "2", and "52". "5" is the only odd number.
"""


class Solution:
    def largestOddNumber(self, num: str) -> str:
        n = len(num)
        for i in range(n - 1, -1, -1):
            if int(num[i]) % 2 == 1:
                return num[:i+1]
        return ""