"""
3170. Lexicographically Minimum String After Removing Stars
    You are given a string s. It may contain any number of '*' characters. Your task is to remove all '*' characters.
    While there is a '*', do the following operation:
    Delete the leftmost '*' and the smallest non-'*' character to its left. If there are several smallest characters, you can delete any of them.
    Return the lexicographically smallest resulting string after removing all '*' characters.

    Example :
    Input: s = "aaba*"
    Output: "aab"
    Explanation:
    We should delete one of the 'a' characters with '*'. If we choose s[3], s becomes the lexicographically smallest.
"""


class Solution:
    def clearStars(self, s: str) -> str:
        if "*" not in s:
            return s
        s0 = []
        stack = [[] for _ in range(26)]
        for idx, ch in enumerate(s):
            if ch == "*":
                if not s0:
                    continue
                x = s0[0]
                if not (v := stack[x]):
                    continue
                v.pop()
                if not v:
                    heapq.heappop(s0)
            else:
                x = ord(ch) - 97
                v = stack[x]
                if not v:
                    heapq.heappush(s0, x)
                v.append(idx)
        return "".join(s[i] for i in sorted(itertools.chain.from_iterable(stack)))