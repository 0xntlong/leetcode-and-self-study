"""
3518. Smallest Palindromic Rearrangement II
    You are given a palindromic string s and an integer k.
    Return the k-th lexicographically smallest palindromic permutation of s. If there are fewer than k distinct palindromic permutations, return an empty string.
    Note: Different rearrangements that yield the same palindromic string are considered identical and are counted once.
    
    Example:
    Input: s = "abba", k = 2
    Output: "baab"
    Explanation:
    The two distinct palindromic rearrangements of "abba" are "abba" and "baab".
    Lexicographically, "abba" comes before "baab". Since k = 2, the output is "baab".
"""

from typing import List
import collections
import math
class Solution:
    def smallestPalindrome(self, S: str, K: int) -> str:
        n = len(S)
        ans = [""] * n
        count = collections.Counter(S[:n // 2])

        if n & 1:
            ans[n // 2] = S[n // 2]

        total = 0
        ways = 1
        index = 0

        for c in sorted(count, reverse=True):
            total += count[c]
            ways *= math.comb(total, count[c])

            if ways > K:
                for c2 in sorted(count):
                    if c2 >= c:
                        break
                    for _ in range(count[c2]):
                        ans[index] = ans[~index] = c2
                        index += 1
                    count[c2] = 0

        ways = 1
        total = sum(count.values())

        for c in sorted(count):
            ways *= math.comb(total, count[c])
            total -= count[c]

        if ways < K:
            return ""

        total = sum(count.values())

        while total:
            for c in sorted(count):
                if count[c]:
                    ways2 = ways * count[c] // total

                    if ways2 < K:
                        K -= ways2
                    else:
                        ans[index] = ans[~index] = c
                        index += 1
                        ways = ways2
                        count[c] -= 1
                        total -= 1
                        break

        return "".join(ans)