"""
2027. Minimum Moves to Convert String
    You are given a string s consisting of n characters which are either 'X' or 'O'.
    A move is defined as selecting three consecutive characters of s and converting them to 'O'. Note that if a move is applied to the character 'O', it will stay the same.
    Return the minimum number of moves required so that all the characters of s are converted to 'O'.

    Example :
    Input: s = "XXX"
    Output: 1
    Explanation: XXX -> OOO
    We select all the 3 characters and convert them in one move.
"""

class Solution:
    def minimumMoves(self, s: str) -> int:
        i = 0
        n = len(s)
        count = 0
        while i < n:
            if s[i] == "X":
                count += 1
                i += 3
            else: 
                i += 1
        return count