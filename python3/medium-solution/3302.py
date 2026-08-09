"""
3302. Find the Lexicographically Smallest Valid Sequence
    You are given two strings word1 and word2.
    A string x is called almost equal to y if you can change at most one character in x to make it identical to y.
    A sequence of indices seq is called valid if:
    The indices are sorted in ascending order.
    Concatenating the characters at these indices in word1 in the same order results in a string that is almost equal to word2.
    Return an array of size word2.length representing the lexicographically smallest valid sequence of indices. If no such sequence of indices exists, return an empty array.
    Note that the answer must represent the lexicographically smallest array, not the corresponding string formed by those indices.

    Example :
    Input: word1 = "vbcca", word2 = "abc"
    Output: [0,1,2]
    Explanation:
    The lexicographically smallest valid sequence of indices is [0, 1, 2]:
    Change word1[0] to 'a'.
    word1[1] is already 'b'.
    word1[2] is already 'c'.
"""


from typing import List

class Solution:
    def validSequence(self, word1: str, word2: str) -> List[int]:
        n2 = len(word2)

        dp2 = [-1] * n2
        j = n2 - 1

        for i in range(len(word1) - 1, -1, -1):
            if j >= 0 and word1[i] == word2[j]:
                dp2[j] = i
                j -= 1

        changed = 0
        j = 0
        res = []

        for i, ch in enumerate(word1):
            if j >= n2:
                break

            if ch == word2[j]:
                res.append(i)
                j += 1

            elif changed == 0:
                if j == n2 - 1 or i + 1 <= dp2[j + 1]:
                    changed = 1
                    res.append(i)
                    j += 1

        return res if j == n2 else []