"""
3090. Maximum Length Substring With Two Occurrences
    Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
    Example :
    Input: s = "bcbbbcba"
    Output: 4
    Explanation:
    The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
"""



from collections import defaultdict


class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        count = defaultdict(int)
        left = 0
        ans = 0

        for right, ch in enumerate(s):
            count[ch] += 1

            while count[ch] > 2:
                count[s[left]] -= 1
                left += 1

            ans = max(ans, right - left + 1)

        return ans