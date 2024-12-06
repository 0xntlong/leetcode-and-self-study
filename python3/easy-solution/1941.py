"""
1941. Check if All Characters Have Equal Number of Occurrences
    Given a string s, return true if s is a good string, or false otherwise.
    A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).
    
    Example :
    Input: s = "abacbc"
    Output: true
    Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.
"""

from collections import Counter
class Solution:
    def areOccurrencesEqual(self, s: str) -> bool:
        freq = Counter(s)
        return len(set(freq.values())) == 1