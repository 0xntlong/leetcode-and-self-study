"""
3136. Valid Word
    A word is considered valid if:
    It contains a minimum of 3 characters.
    It contains only digits (0-9), and English letters (uppercase and lowercase).
    It includes at least one vowel.
    It includes at least one consonant.
    You are given a string word.
    Return true if word is valid, otherwise, return false.
    Notes:
    'a', 'e', 'i', 'o', 'u', and their uppercases are vowels.
    A consonant is an English letter that is not a vowel.

    Example :
    Input: word = "234Adas"
    Output: true
    Explanation:
    This word satisfies the conditions.
"""



class Solution:
    def isValid(self, word: str) -> bool:
        if len(word) < 3:
            return False
        vowels = set("aeiouAEIOU")
        has_vowels = False
        has_cons = False
        for c in word:
            if not (c.isalpha() or c.isdigit()):
                return False
            if c.isalpha():
                if c in vowels:
                    has_vowels = True
                else:
                    has_cons = True
        return has_vowels and has_cons