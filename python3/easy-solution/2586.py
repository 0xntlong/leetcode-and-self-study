"""
2586. Count the Number of Vowel Strings in Range
    You are given a 0-indexed array of string words and two integers left and right.
    A string is called a vowel string if it starts with a vowel character and ends with a vowel character where vowel characters are 'a', 'e', 'i', 'o', and 'u'.
    Return the number of vowel strings words[i] where i belongs to the inclusive range [left, right].

    Example :
    Input: words = ["are","amy","u"], left = 0, right = 2
    Output: 2
    Explanation: 
    - "are" is a vowel string because it starts with 'a' and ends with 'e'.
    - "amy" is not a vowel string because it does not end with a vowel.
    - "u" is a vowel string because it starts with 'u' and ends with 'u'.
    The number of vowel strings in the mentioned range is 2.
"""

from typing import List
class Solution:
    def vowelStrings(self, words: List[str], left: int, right: int) -> int:
        char = 0
        vowel = {'a','e','i','o','u'}
        for i in range(left, right + 1):
            word = words[i]
            if (word[0] in vowel and word[-1] in vowel):
                char += 1

        return char 