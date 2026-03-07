"""
1888. Minimum Number of Flips to Make the Binary String Alternating
    You are given a binary string s. You are allowed to perform two types of operations on the string in any sequence:
    Type-1: Remove the character at the start of the string s and append it to the end of the string.
    Type-2: Pick any character in s and flip its value, i.e., if its value is '0' it becomes '1' and vice-versa.
    Return the minimum number of type-2 operations you need to perform such that s becomes alternating.
    The string is called alternating if no two adjacent characters are equal.
    For example, the strings "010" and "1010" are alternating, while the string "0100" is not.
    
    Example :

    Input: s = "111000"
    Output: 2
    Explanation: Use the first operation two times to make s = "100011".
    Then, use the second operation on the third and sixth elements to make s = "101010".
"""

from typing import List, Optional, Tuple, Dict, Set

class Solution:
    def minFlips(self, s: str) -> int:
        prev = 0
        s0 = 0
        s1 = 0
        s0_odd = float('inf')
        s1_odd = float('inf')
        odd = len(s) % 2
        for val in s:
            val = int(val)
            if val == prev:
                if odd:
                    s0_odd = min(s0_odd, s1)
                    s1_odd += 1
                s1 += 1
            else:
                if odd:
                    s1_odd = min(s1_odd, s0)
                    s0_odd += 1
                s0 += 1
            prev = 1 - prev
        return min(s0, s1, s0_odd, s1_odd)