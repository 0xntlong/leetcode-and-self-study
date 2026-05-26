"""
3120. Count the Number of Special Characters I
    You are given a string word. A letter is called special if it appears both in lowercase and uppercase in word.
    Return the number of special letters in word.
    Example :
    Input: word = "aaAbcBC"
    Output: 3
    Explanation:
    The special characters in word are 'a', 'b', and 'c'.
"""


from typing import Set
class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        lower = set()
        upper = set()
        for c in word:
            if c.islower():
                lower.add(c)
            else:
                upper.add(c.lower())
        return len(lower & upper)