"""
1639. Number of Ways to Form a Target String Given a Dictionary
    You are given a list of strings of the same length words and a string target.
    Your task is to form target using the given words under the following rules:
    target should be formed from left to right.
    To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if target[i] = words[j][k].
    Once you use the kth character of the jth string of words, you can no longer use the xth character of any string in words where x <= k. In other words, all characters to the left of or at index k become unusuable for every string.
    Repeat the process until you form the string target.
    Notice that you can use multiple characters from the same string in words provided the conditions above are met.
    Return the number of ways to form target from words. Since the answer may be too large, return it modulo 109 + 7.

    Example :
    Input: words = ["acca","bbbb","caca"], target = "aba"
    Output: 6
    Explanation: There are 6 ways to form target.
    "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("caca")
    "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("caca")
    "aba" -> index 0 ("acca"), index 1 ("bbbb"), index 3 ("acca")
    "aba" -> index 0 ("acca"), index 2 ("bbbb"), index 3 ("acca")
    "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("acca")
    "aba" -> index 1 ("caca"), index 2 ("bbbb"), index 3 ("caca")
"""

from typing import List

class Solution:
    def numWays(self, words: List[str], target: str) -> int:
        MOD = 10 ** 9 + 7

        word_L = len(words[0])
        target_L = len(target)
        charFrequency = [[0] * 26 for _ in range(word_L)]

        for word in words:
            for idx, char in enumerate(word):
                charFrequency[idx][ord(char) - ord('a')] += 1
            
        dp = [0] * (target_L + 1)
        dp[0] = 1

        for i in range(word_L):
            for j in range(target_L - 1, -1, -1):
                if charFrequency[i][ord(target[j]) - ord('a')] > 0:
                    dp[j + 1] += dp[j] * charFrequency[i][ord(target[j]) - ord('a')]
                    dp[j + 1] %= MOD
                    
        return dp[target_L]