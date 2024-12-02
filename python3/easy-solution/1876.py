"""
1876. Substrings of Size Three with Distinct Characters
    A string is good if there are no repeated characters.
    Given a string s​​​​​, return the number of good substrings of length three in s​​​​​​.
    Note that if there are multiple occurrences of the same substring, every occurrence should be counted.
    A substring is a contiguous sequence of characters in a string.
    
    Example :
    Input: s = "xyzzaz"
    Output: 1
    Explanation: There are 4 substrings of size 3: "xyz", "yzz", "zza", and "zaz". 
    The only good substring of length 3 is "xyz".
"""


class Solution:
    def countGoodSubstrings(self, s: str) -> int:
        count = 0
        if len(s) < 3:
            return 0
        for i in range(len(s) - 2):
            if s[i] != s[i + 1] and s[i] != s[i + 2] and s[i + 1] != s[i + 2]:
                count += 1
        return count