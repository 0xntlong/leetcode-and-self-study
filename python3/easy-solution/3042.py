"""
3042. Count Prefix and Subffix Pairs I
    You are given a 0-indexed string array words.
    Let's define a boolean function isPrefixAndSuffix that takes two strings, str1 and str2:
        + isPrefixAndSuffix( str1, str2) returns true if str1 is both a prefix and a suffix of str2, and false otherwise.
    For example, isPrefixAndSuffix( "aba", "ababa") is true because "aba" is a prefix of "ababa" and also a suffix, but isPrefixAndSuffix("abc", "abcd") is false.
    Return an integer denoting the number of index pairs (i, j) such that i < j, and isPrefixAndSuffix(words[i], words[j]) is true.
    Example :
    Input: words = [ "a","aba","ababa","aa"]
    Output: 
    Explanation: In this example, the counted index pairs are:
    i = 0 and j = 1 because isPrefixAndSuffix( "a", "aba") is true.
    i = 0 and j = 2 because isPrefixAndSuffix( "a", "ababa") is true.
    i = 0 and j = 3 because isPrefixAndSuffix( "a", "aa") is true.
    i = 1 and j = 2 because isPrefixAndSuffix( "aba", "ababa") is true.
    Therefore, the answer is 4.
"""

from typing import List
class Solution:
    def isPrefixAndSuffix(self, str1: str, str2: str) -> bool:
        n = len(str1)
        m = len(str2)
        if n > m:
            return False
        return str2[:n] == str1 and str2[-n:] == str1
        
    def countPrefixSuffixPairs(self, words: List[str]) -> int:
        count = 0 
        n = len(words)
        for i in range(n):
            for j in range(i + 1, n):
                if self.isPrefixAndSuffix(words[i], words[j]):
                    count += 1
        return count