"""
2566. Maximum Difference by Remapping a Digit
    You are given an integer num. You know that Bob will sneakily remap one of the 10 possible digits (0 to 9) to another digit.
    Return the difference between the maximum and minimum values Bob can make by remapping exactly one digit in num.
    Notes:
    When Bob remaps a digit d1 to another digit d2, Bob replaces all occurrences of d1 in num with d2.
    Bob can remap a digit to itself, in which case num does not change.
    Bob can remap different digits for obtaining minimum and maximum values respectively.
    The resulting number after remapping can contain leading zeroes.

    Example:
    Input: num = 11891
    Output: 99009
    Explanation: 
    To achieve the maximum value, Bob can remap the digit 1 to the digit 9 to yield 99899.
    To achieve the minimum value, Bob can remap the digit 1 to the digit 0, yielding 890.
    The difference between these two numbers is 99009.
"""


class Solution:
    def minMaxDifference(self, num: int) -> int:
        numStr = str(num)

        digits = [int(d) for d in list(numStr)]
        n = len(digits)

        d1 = digits[0]
        i = 0
        while (i < n):
            if (digits[i] != 9):
                d1 = digits[i]
                break
            i += 1
        d2 = digits[0]
        i = 0
        while (i < n):
            if (digits[i] != 0):
                d2 = digits[i]
                break
            i += 1
        max_num = int(''.join(['9' if d == d1 else str(d) for d in digits]))
        min_num = int(''.join(['0' if d == d2 else str(d) for d in digits]))

        return max_num - min_num