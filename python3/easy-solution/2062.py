"""
2062. Count Vowel Substrings of a String
    A substring is a contiguous (non-empty) sequence of characters within a string.
    A vowel substring is a substring that only consists of vowels ('a', 'e', 'i', 'o', and 'u') and has all five vowels present in it.
    Given a string word, return the number of vowel substrings in word.

    Example :
    Input: word = "aeiouu"
    Output: 2
    Explanation: The vowel substrings of word are as follows (underlined):
    - "aeiouu"
    - "aeiouu"
"""

from collections import defaultdict
class Solution:
    def countVowelSubstrings(self, word: str) -> int:
        ans = 0
        freq = defaultdict(int)
        for i, char in enumerate(word):
            if char in "aeiou":
                if not i or word[i - 1] not in "aeiou":
                    x = y = i
                    freq.clear()
                freq[char] += 1
                while len(freq) == 5 and all(freq.values()):
                    freq[word[y]] -= 1
                    y += 1
                ans += y - x
        return ans