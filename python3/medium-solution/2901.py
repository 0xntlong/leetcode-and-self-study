"""
2901. Longest Unequal Adjacent Groups Subsequence II
    You are given a string array words, and an array groups, both arrays having length n.
    The hamming distance between two strings of equal length is the number of positions at which the corresponding characters are different.
    You need to select the longest subsequence from an array of indices [0, 1, ..., n - 1], such that for the subsequence denoted as [i0, i1, ..., ik-1] having length k, the following holds:
    For adjacent indices in the subsequence, their corresponding groups are unequal, i.e., groups[ij] != groups[ij+1], for each j where 0 < j + 1 < k.
    words[ij] and words[ij+1] are equal in length, and the hamming distance between them is 1, where 0 < j + 1 < k, for all indices in the subsequence.
    Return a string array containing the words corresponding to the indices (in order) in the selected subsequence. If there are multiple answers, return any of them.
    Note: strings in words may be unequal in length.

    Example 1:
    Input: words = ["bab","dab","cab"], groups = [1,2,2]
    Output: ["bab","cab"]
    Explanation: A subsequence that can be selected is [0,2].
    groups[0] != groups[2]
    words[0].length == words[2].length, and the hamming distance between them is 1.
    So, a valid answer is [words[0],words[2]] = ["bab","cab"].
    Another subsequence that can be selected is [0,1].
    groups[0] != groups[1]
    words[0].length == words[1].length, and the hamming distance between them is 1.
    So, another valid answer is [words[0],words[1]] = ["bab","dab"].
    It can be shown that the length of the longest subsequence of indices that satisfies the conditions is 2.
"""

from typing import List

class Solution:
    def hamming(self, s : str, t : str) -> bool:
        if len(s) != len(t):
            return False
        diff = 0
        for a, b in zip(s, t):
            if a != b:
                diff += 1
                if diff > 1:
                    return False
        return diff == 1

    def getWordsInLongestSubsequence(self, words: List[str], groups: List[int]) -> List[str]:
        n = len(words)
        dp = [1] * n
        nxt = [-1] * n
        max_len = 0
        start = -1
        for i in reversed(range(n)):
            for j in range(i + 1, n):
                if groups[i] != groups[j] and self.hamming(words[i], words[j]):
                    if dp[j] + 1 > dp[i]:
                        dp[i] = dp[j] + 1
                        nxt[i] = j
            if dp[i] > max_len:
                max_len = dp[i]
                start = i
        res = []
        while start != -1:
            res.append(words[start])
            start = nxt[start]
        return res