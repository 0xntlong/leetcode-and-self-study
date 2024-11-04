"""
3163. String Comperssion III
    Given a string word, compress it using the following algorithm: 
    Begin with an empty string comp. While word is not empty, use the following operation:
    Remove a maximum length prefix of word made of a single character c repeating at most 9 times.
    Append the length of the prefix followed by c to comp.
    Return the string comp.

    Example :
    Input: word = "abcde"
    Output: "1a1b1c1d1e"
    Explanation:
    Initially, comp = "". Apply the operation 5 times, choosing "a", "b", "c", "d", and "e" as the prefix in each operation.
    For each prefix, append "1" followed by the character to comp.
"""

class Solution:
    def compressedString(self, word: str) -> str:
        comp = ""
        count = 1
        n = len(word)
        char = word[0]
        for i in range(1, n):
            if word[i] == char and count < 9:
                count += 1
            else :
                comp += str(count) + char
                char = word[i]
                count = 1
        comp += str(count) + char
        return comp