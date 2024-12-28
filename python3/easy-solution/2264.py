"""
2264. Largest 3-Same-Digit Number in String
    You are given a string num representing a large integer. An integer is good if it meets the following conditions:
    It is a substring of num with length 3.
    It consists of only one unique digit.
    Return the maximum good integer as a string or an empty string "" if no such integer exists.
    Note:
    A substring is a contiguous sequence of characters within a string.
    There may be leading zeroes in num or a good integer.

    Example :
    Input: num = "6777133339"
    Output: "777"
    Explanation: There are two distinct good integers: "777" and "333".
    "777" is the largest, so we return "777".
"""


class Solution:
    def largestGoodInteger(self, num: str) -> str:
        res = ""
        for i in range(len(num) - 2):
            if num[i] == num[i + 1] == num[i + 2]:
                if not res or num[i:i+3] > res:
                    res = num[i:i+3]
        return res