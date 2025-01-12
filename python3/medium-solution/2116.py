"""
2116. Check if a Parentheses String Can Be Valid
    A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
    It is ().
    It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
    It can be written as (A), where A is a valid parentheses string.
    You are given a parentheses string s and a string locked, both of length n. locked is a binary string consisting only of '0's and '1's. For each index i of locked,
    If locked[i] is '1', you cannot change s[i].
    But if locked[i] is '0', you can change s[i] to either '(' or ')'.
    Return true if you can make s a valid parentheses string. Otherwise, return false.

    Example :
    Input: s = "))()))", locked = "010100"
    Output: true
    Explanation: locked[1] == '1' and locked[3] == '1', so we cannot change s[1] or s[3].
    We change s[0] and s[4] to '(' while leaving s[2] and s[5] unchanged to make s valid.
"""


class Solution:
    def canBeValid(self, s: str, locked: str) -> bool:
        n = len(s)
        if n % 2 != 0:
            return False
        count = 0
        for i in range(n):
            if locked[i] == '0' or s[i] == '(':
                count += 1
            else:
                count -= 1
            if count < 0:
                return False
        count = 0
        for i in range(n - 1, -1, -1):
            if locked[i] == '0' or s[i] == ')':
                count += 1
            else:
                count -= 1
            if count < 0:
                return False
        return True