"""
3333. Find the Original Typed String II
    Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
    You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.
    Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.
    Since the answer may be very large, return it modulo 109 + 7.

    Example 1:
    Input: word = "aabbccdd", k = 7
    Output: 5
    Explanation:
    The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", and "abbccdd".
"""



class Solution:
    def possibleStringCount(self, word: str, k: int) -> int:
        mod = 10**9 + 7
        cnt = []
        total = 1
        n = len(word)
        i = 0
        while i < n:
            j = i
            while i < n and word[i] == word[j]:
                i += 1
            length = i - j
            if length > 0:
                cnt.append(length - 1)
                total = total * length % mod
            k -= 1
        if k <= 0:
            return total
        dp = [0] * k
        dp[0] = 1
        for c in cnt:
            for i in range(1, k):
                dp[i] = (dp[i] + dp[i - 1]) % mod
            for i in range(k - 1, c, - 1):
                dp[i] = (dp[i] - dp[i - c - 1] + mod) % mod
        for i in range(1, k):
            dp[i] = (dp[i] + dp[i - 1]) % mod
        ans = (total - dp[k - 1] + mod) % mod
        return ans