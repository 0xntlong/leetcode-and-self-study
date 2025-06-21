"""
3085. Minimum Deletions to Make String K-Special
    You are given a string word and an integer k.
    We consider word to be k-special if |freq(word[i]) - freq(word[j])| <= k for all indices i and j in the string.
    Here, freq(x) denotes the frequency of the character x in word, and |y| denotes the absolute value of y.
    Return the minimum number of characters you need to delete to make word k-special.

    Example :
    Input: word = "aabcaba", k = 0
    Output: 3
    Explanation: We can make word 0-special by deleting 2 occurrences of "a" and 1 occurrence of "c". Therefore, word becomes equal to "baba" where freq('a') == freq('b') == 2.
"""

from collections import Counter
from math import inf

class Solution:
    def minimumDeletions(self, word: str, k: int) -> int:
        freq = Counter(word).values()
        res = inf

        for i in freq:
            cur = 0
            for j in freq:
                cur += j if j < i else max(0, j - (i + k))
            res = min(res, cur)
        return res
