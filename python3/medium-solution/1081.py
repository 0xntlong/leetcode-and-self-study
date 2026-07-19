"""
1081. Smallest Subsequence of Distinct Characters
    Given a string s, return the lexicographically smallest subsequence of s that contains all the distinct characters of s exactly once.

    Example :
    Input: s = "bcabc"
    Output: "abc"
"""



class Solution:
    def smallestSubsequence(self, s: str) -> str:
        freq = {c : 0 for c in s}
        visited = set()
        stack = []
        for c in s:
            freq[c] += 1

        for c in s:
            freq[c] -= 1
            if c in visited:
                continue
            while stack and stack[-1] > c and freq[stack[-1]] > 0:
                visited.remove(stack.pop())
            stack.append(c)
            visited.add(c)
        return "".join(stack)