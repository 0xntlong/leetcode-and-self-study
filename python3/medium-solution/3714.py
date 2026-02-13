"""
3714. Longest Balanced Substring II
    You are given a string s consisting only of the characters 'a', 'b', and 'c'.
    A substring of s is called balanced if all distinct characters in the substring appear the same number of times.
    Return the length of the longest balanced substring of s.
    Example :
    Input: s = "abbac"
    Output: 4
    Explanation:
    The longest balanced substring is "abba" because both distinct characters 'a' and 'b' each appear exactly 2 times.
"""



class Solution:
    def longestBalanced(self, s: str) -> int:
        n = len(s)
        ans = i = 0
        while i < n:
            start = i
            i += 1
            while i < n and s[i] == s[i - 1]:
                i += 1
            ans = max(ans, i - start)
        def f(x: str, y: str) -> None:
            nonlocal ans
            i = 0
            while i < n:
                pos = {0: i - 1}
                d = 0
                while i < n and (s[i] == x or s[i] == y):
                    d += 1 if s[i] == x else -1
                    if d in pos:
                        ans = max(ans, i - pos[d])
                    else:
                        pos[d] = i
                    i += 1
                i += 1

        f('a', 'b')
        f('a', 'c')
        f('b', 'c')
        pos = {(0, 0): -1}
        cnt = defaultdict(int)
        for i, b in enumerate(s):
            cnt[b] += 1
            p = (cnt['a'] - cnt['b'], cnt['b'] - cnt['c'])
            if p in pos:
                ans = max(ans, i - pos[p])
            else:
                pos[p] = i
        return ans