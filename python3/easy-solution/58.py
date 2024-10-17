"""
58. Length of Last Word
    Given a string s consists of some words separated by spaces, return the length of the last word in the string. If the last word does not exist, return 0.
    A word is a maximal substring consisting of non-space characters only.

    Example:
    Input: s = "Hello World"
    Output: 5
    Explanation: The last word is "World" with length 5.  
"""

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        count = 0
        i = len(s) - 1 
        while i >= 0 and s[i] == ' ':
            i -= 1
        while i >= 0 and s[i] != ' ':
            count += 1
            i -= 1
        return count