"""
2559. Count Vowel Strings in Ranges
    You are given a 0-indexed array of strings words and a 2D array of integers queries.
    Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
    Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
    Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.

    Example :
    Input: words = ["aba","bcb","ece","aa","e"], queries = [[0,2],[1,4],[1,1]]
    Output: [2,3,0]
    Explanation: The strings starting and ending with a vowel are "aba", "ece", "aa" and "e".
    The answer to the query [0,2] is 2 (strings "aba" and "ece").
    to query [1,4] is 3 (strings "ece", "aa", "e").
    to query [1,1] is 0.
    We return [2,3,0].
"""

from typing import List
class Solution:
    def vowelStrings(self, words: List[str], queries: List[List[int]]) -> List[int]:
        vowels = {'a', 'e', 'i', 'o', 'u'}
        n = len(words)
        prefix = [0] * (n + 1)
        
        for i in range(n):
            prefix[i+1] = prefix[i] + (words[i][0] in vowels and words[i][-1] in vowels)
        
        result = []
        for i, j in queries:
            result.append(prefix[j+1] - prefix[i])
        
        return result