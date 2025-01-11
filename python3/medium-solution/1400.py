"""
1400. Construct K Palindrome Strings
    Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

    Example :
    Input: s = "annabelle", k = 2
    Output: true
    Explanation: You can construct two palindromes using all characters in s.
    Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
"""

from collections import Counter
class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        n = len(s)
        if n < k:
            return False
        freq = Counter(s)
        odd_count = sum(1 for count in freq.values() if count % 2 != 0)
        return odd_count <= k