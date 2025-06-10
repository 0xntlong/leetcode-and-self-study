"""
3442. Maximum Difference Between Even and Odd Frequency I
    You are given a string s consisting of lowercase English letters.
    Your task is to find the maximum difference diff = freq(a1) - freq(a2) between the frequency of characters a1 and a2 in the string such that:
    a1 has an odd frequency in the string.
    a2 has an even frequency in the string.
    Return this maximum difference.


    Example :
    Input: s = "aaaaabbc"
    Output: 3
    Explanation:
    The character 'a' has an odd frequency of 5, and 'b' has an even frequency of 2.
    The maximum difference is 5 - 2 = 3.
"""


from collections import Counter
class Solution:
    def maxDifference(self, s: str) -> int:
        freq = Counter(s)
        maxOdd = 0
        minEven = 100
        for f in freq.values():
            if f == 0:
                continue
            if f & 1:
                maxOdd = max(f, maxOdd)
            else:
                minEven = min(f, minEven)
        return maxOdd - minEven
