"""
1869. Longer Contiguous Segments of Ones than Zeros
    Given a binary string s, return true if the longest contiguous segment of 1's is strictly longer than the longest contiguous segment of 0's in s, or return false otherwise.
    For example, in s = "110100010" the longest continuous segment of 1s has length 2, and the longest continuous segment of 0s has length 3.
    Note that if there are no 0's, then the longest continuous segment of 0's is considered to have a length 0. The same applies if there is no 1's.

    Example :
    Input: s = "1101"
    Output: true
    Explanation:
    The longest contiguous segment of 1s has length 2: "1101"
    The longest contiguous segment of 0s has length 1: "1101"
    The segment of 1s is longer, so return true.
"""

from itertools import groupby
import collections

class Solution:
    def checkZeroOnes(self, s: str) -> bool:
        """
        count1, count0 = 0, 0
        freq1, freq0 = 0, 0
        for i in range(len(s)):
            if s[i] == '1':
                count1 += 1
                freq1 = max(freq1, count1)
                count0 = 0
            if s[i] == '0':
                count0 += 1
                freq0 = max(freq0, count0)
                count1 = 0
        return freq1 > freq0
        """
        freq = collections.defaultdict(int)
        for x, y in groupby(s):
            freq[x] = max(freq[x], len(list(y)))
        return freq["1"] > freq["0"]