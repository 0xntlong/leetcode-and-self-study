"""
1668. Maximum Repeating Substring
    For a string sequence, a string word is k-repeating if word concatenated k times is a substring of sequence. The word's maximum k-repeating value is the highest value k where word is k-repeating in sequence. If word is not a substring of sequence, word's maximum k-repeating value is 0.
    Given strings sequence and word, return the maximum k-repeating value of word in sequence.

    Example 1:
    Input: sequence = "ababc", word = "ab"
    Output: 2
    Explanation: "abab" is a substring in "ababc".
"""


class Solution:
    def maxRepeating(self, sequence: str, word: str) -> int:
        count = 0
        k = word
        while k in sequence:
            count += 1
            k += word
        return count