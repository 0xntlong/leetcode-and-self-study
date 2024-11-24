"""
1758. Minimum Changes To Make Alternating Binary String
    You are given a string s consisting only of the characters '0' and '1'. In one operation, you can change any '0' to '1' or vice versa.
    The string is called alternating if no two adjacent characters are equal. For example, the string "010" is alternating, while the string "0100" is not.
    Return the minimum number of operations needed to make s alternating.

    Example:
    Input: s = "0100"
    Output: 1
    Explanation: If you change the last character to '1', s will be "0101", which is alternating.
"""

class Solution:
    def minOperations(self, s: str) -> int:
        zero , one = 0, 0
        for i in range(len(s)):
            if s[i] != ('0' if i % 2 == 0 else '1'):
                zero += 1
            if s[i] != ('1' if i % 2 == 0 else '0'):
                one += 1
        return min(zero, one)