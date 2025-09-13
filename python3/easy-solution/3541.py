"""
3541. Find Most Frequent Vowel and Consonant
    You are given a string s consisting of lowercase English letters ('a' to 'z').
    Your task is to:
    Find the vowel (one of 'a', 'e', 'i', 'o', or 'u') with the maximum frequency.
    Find the consonant (all other letters excluding vowels) with the maximum frequency.
    Return the sum of the two frequencies.
    Note: If multiple vowels or consonants have the same maximum frequency, you may choose any one of them. If there are no vowels or no consonants in the string, consider their frequency as 0.
    The frequency of a letter x is the number of times it occurs in the string.

    Example :
    Input: s = "successes"
    Output: 6
    Explanation:
    The vowels are: 'u' (frequency 1), 'e' (frequency 2). The maximum frequency is 2.
    The consonants are: 's' (frequency 4), 'c' (frequency 2). The maximum frequency is 4.
    The output is 2 + 4 = 6.
"""



class Solution:
    def maxFreqSum(self, s: str) -> int:
        vowels = set("aeiou")
        freq = [0] * 26
        max_vowel = 0
        max_cons = 0
        for c in s:
            idx = ord(c) - ord('a')
            freq[idx] += 1
            if c in vowels:
                max_vowel = max(max_vowel, freq[idx])
            else:
                max_cons = max(max_cons, freq[idx])
        return max_vowel + max_cons