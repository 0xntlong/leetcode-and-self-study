"""
1704. Determine if String Halves Are Alike
    You are given a string s of even length. Split this string into two halves of equal lengths, and let a be the first half and b be the second half.
    Two strings are alike if they have the same number of vowels ('a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'). Notice that s contains uppercase and lowercase letters.
    Return true if a and b are alike. Otherwise, return false.

    Example :
    Input: s = "book"
    Output: true
    Explanation: a = "bo" and b = "ok". a has 1 vowel and b has 1 vowel. Therefore, they are alike.
"""


class Solution:
    def isVowels(self, c):
        return c in "AEIOUaeiou"
    def halvesAreAlike(self, s: str) -> bool:
        n = len(s)
        first = s[:n // 2]
        second = s[n // 2:]
        f = sum(1 for c in first if self.isVowels(c))
        s = sum(1 for c in second if self.isVowels(c))
        return f == s