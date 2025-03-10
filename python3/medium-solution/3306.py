"""
3306. Count of Substrings Containing Every Vowel and K Consonants II
    You are given a string word and a non-negative integer k.
    Return the total number of substrings of word that contain every vowel ('a', 'e', 'i', 'o', and 'u') at least once and exactly k consonants.

    Example :
    Input: word = "aeioqq", k = 1
    Output: 0
    Explanation:
    There is no substring with every vowel.
"""

from collections import defaultdict
class Solution:
    def countOfSubstrings(self, word: str, k: int) -> int:
        n = len(word)
        vowels = set('aeiou')
        vowelCount = defaultdict(int)
        cons = 0
        left = count = substr = 0
        def minus(c):
            if c in vowels:
                vowelCount[c] -= 1
                if vowelCount[c] == 0:
                    del vowelCount[c]
            else:
                nonlocal cons
                cons -= 1
        for c in word:
            if c in vowels:
                vowelCount[c] += 1
            else:
                cons += 1
                count = 0
            while cons > k:
                minus(word[left])
                left += 1
            while cons == k and len(vowelCount) == 5:
                count += 1
                minus(word[left])
                left += 1
            substr += count
        return substr