"""
1520. Maximum Number of Non-Overlapping Substrings
    Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:
    The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
    A substring that contains a certain character c must also contain all occurrences of c.
    Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.
    Notice that you can return the substrings in any order.

    Example :
    Input: s = "adefaddaccc"
    Output: ["e","f","ccc"]
    Explanation: The following are all the possible substrings that meet the conditions:
    [
    "adefaddaccc"
    "adefadda",
    "ef",
    "e",
    "f",
    "ccc",
    ]
    If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.
"""



from collections import Counter, deque
from math import inf


class Solution:
    def maxNumOfSubstrings(self, s: str) -> list[str]:
        counts = Counter(s)
        first = {c: s.find(c) for c in counts}
        last = {c: s.rfind(c) for c in counts}

        res = []
        queue = deque()

        for c in counts:
            queue.appendleft([first[c], last[c], counts[c]])

            left = inf
            right = -inf
            total = 0

            for x, y, z in queue:
                total += z
                left = min(left, x)
                right = max(right, y)

                if total == right - left + 1:
                    break

            if total == right - left + 1:
                res.append(s[left:right + 1])
                queue.clear()

        return res