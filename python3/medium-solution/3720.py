"""
3720. Lexicographically Smallest Permutation Greater Than Target
    You are given two strings s and target, both having length n, consisting of lowercase English letters.
    Return the lexicographically smallest permutation of s that is strictly greater than target. If no permutation of s is lexicographically strictly greater than target, return an empty string.
    A string a is lexicographically strictly greater than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b.

    Example :
    Input: s = "abc", target = "bba"
    Output: "bca"
    Explanation:
    The permutations of s (in lexicographical order) are "abc", "acb", "bac", "bca", "cab", and "cba".
    The lexicographically smallest permutation that is strictly greater than target is "bca".
"""


class Solution:
    def lexGreaterPermutation(self, s: str, target: str) -> str:
        n = len(s)
        cnt = [0] * 26
        for ch in s:
            cnt[ord(ch) - 97] += 1
        p = 0
        while p < n:
            c = ord(target[p]) - 97
            if cnt[c] == 0:
                break
            cnt[c] -= 1
            p += 1

        i = p
        while i >= 0:
            if i < n:
                t = ord(target[i]) - 97
                pick = -1
                for c in range(t + 1, 26):
                    if cnt[c] > 0:
                        pick = c
                        break
                if pick >= 0:
                    cnt[pick] -= 1
                    tail = ''.join(chr(97 + c) * cnt[c] for c in range(26))
                    cnt[pick] += 1
                    return target[:i] + chr(97 + pick) + tail
            i -= 1
            if i >= 0:
                cnt[ord(target[i]) - 97] += 1
        return ""