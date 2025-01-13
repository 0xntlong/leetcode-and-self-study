"""
3223. Minimum Length of String After Operatons
    You are given a string s.
    You can perform the following process on s any number of times:
    Choose an index i in the string such that there is at least one character to the left of index i that is equal to s[i], and at least one character to the right that is also equal to s[i].
    Delete the closest character to the left of index i that is equal to s[i].
    Delete the closest character to the right of index i that is equal to s[i].
    Return the minimum length of the final string s that you can achieve.

    Example :
    Input: s = "abaacbcbb"
    Output: 5
    Explanation:
    We do the following operations:
    Choose index 2, then remove the characters at indices 0 and 3. The resulting string is s = "bacbcbb".
    Choose index 3, then remove the characters at indices 0 and 5. The resulting string is s = "acbcb".
"""



"""
# 1 Line Approach
class Solution:
    def minimumLength(self, s: str) -> int:
        return sum(1 if i % 2 else 2 for i in Counter(s).values())
"""


class Solution:
    def minimumLength(self, s: str) -> int:
        freq = [0] * 26
        count = 0
        for c in s:
            freq[ord(c) - ord('a')] += 1
        for i in freq:
            if i == 0:
                continue
            if i % 2 == 0:
                count += 2
            else:
                count += 1
        return count