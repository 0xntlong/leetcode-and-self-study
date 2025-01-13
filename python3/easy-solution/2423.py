"""
2423 Remove Letter To Equalize Frequency
    You are given a 0-indexed string word, consisting of lowercase English letters. You need to select one index and remove the letter at that index from word so that the frequency of every letter present in word is equal.
    Return true if it is possible to remove one letter so that the frequency of all letters in word are equal, and false otherwise.
    Note:
    The frequency of a letter x is the number of times it occurs in the string.
    You must remove exactly one letter and cannot choose to do nothing.
    Example :
    Input: word = "abcc"
    Output: true
    Explanation: Select index 3 and delete it: word becomes "abc" and each character has a frequency of 1.
"""


from collections import Counter

class Solution:
    def equalFrequency(self, word: str) -> bool:
        freq = Counter(word)
        for c in freq:
            freq[c] -= 1
            remain = [x for x in freq.values() if x > 0]
            if len(set(remain)) == 1:
                return True
            freq[c] += 1
        return False
    