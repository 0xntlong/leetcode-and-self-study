"""
2283. Check if Number Has Equal Digit Count and Digit Value
    You are given a 0-indexed string num of length n consisting of digits.
    Return true if for every index i in the range 0 <= i < n, the digit i occurs num[i] times in num, otherwise return false.

    Example :
    Input: num = "1210"
    Output: true
    Explanation:
    num[0] = '1'. The digit 0 occurs once in num.
    num[1] = '2'. The digit 1 occurs twice in num.
    num[2] = '1'. The digit 2 occurs once in num.
    num[3] = '0'. The digit 3 occurs zero times in num.
    The condition holds true for every index in "1210", so return true.
"""


class Solution:
    def digitCount(self, num: str) -> bool:
        n = len(num)
        freq = [0] * 10
        for c in num:
            freq[int(c)] += 1
        for i in range(n):
            if freq[i] != int(num[i]):
                return False
        return True