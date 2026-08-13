"""
2213. Longest Substring of One Repeating Character
    You are given a 0-indexed string s. You are also given a 0-indexed string queryCharacters of length k and a 0-indexed array of integer indices queryIndices of length k, both of which are used to describe k queries.
    The ith query updates the character in s at index queryIndices[i] to the character queryCharacters[i].
    Return an array lengths of length k where lengths[i] is the length of the longest substring of s consisting of only one repeating character after the ith query is performed.
    Example :
    Input: s = "babacc", queryCharacters = "bcb", queryIndices = [1,3,3]
    Output: [3,3,4]
    Explanation: 
    - 1st query updates s = "bbbacc". The longest substring consisting of one repeating character is "bbb" with length 3.
    - 2nd query updates s = "bbbccc". 
    The longest substring consisting of one repeating character can be "bbb" or "ccc" with length 3.
    - 3rd query updates s = "bbbbcc". The longest substring consisting of one repeating character is "bbbb" with length 4.
    Thus, we return [3,3,4].
"""


from typing import List

class Solution:
    def longestRepeating(self, s: str, queryCharacters: str, queryIndices: List[int]) -> List[int]:
        n = len(s)
        tree = [None] * (4 * n)
        def merge(left, right):
            if left is None:
                return right
            if right is None:
                return left
            lc, lrc, llen, lp, ls, lb = left
            rlc, rc, rlen, rp, rs, rb = right
            length = llen + rlen

            prefix = lp

            if lrc == rlc and lp == llen:
                prefix = llen + rp

            suffix = rs

            if lrc == rlc and rs == rlen:
                suffix = rlen + ls

            best = max(lb, rb)

            if lrc == rlc:
                best = max(best, ls + rp)

            return [lc, rc, length, prefix, suffix, best]

        def build(node, start, end):
            if start == end:
                tree[node] = [s[start], s[start], 1, 1, 1, 1]
                return

            mid = (start + end) // 2

            build(node * 2, start, mid)
            build(node * 2 + 1, mid + 1, end)

            tree[node] = merge(tree[node * 2], tree[node * 2 + 1])

        def update(node, start, end, index, char):
            if start == end:
                tree[node] = [char, char, 1, 1, 1, 1]
                return

            mid = (start + end) // 2

            if index <= mid:
                update(node * 2, start, mid, index, char)
            else:
                update(node * 2 + 1, mid + 1, end, index, char)

            tree[node] = merge(tree[node * 2], tree[node * 2 + 1])

        build(1, 0, n - 1)

        answer = []

        for char, index in zip(queryCharacters, queryIndices):
            update(1, 0, n - 1, index, char)
            answer.append(tree[1][5])

        return answer