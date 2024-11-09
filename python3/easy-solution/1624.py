"""
1624. Largest Number After Mutating Substring
    Given a string s, return the length of the longest substring between two equal characters, excluding the two characters. If there is no such substring return -1.
    A substring is a contiguous sequence of characters within a string.
    
    Example :
    Input: s = "aa"
    Output: 0
    Explanation: The optimal substring here is an empty substring between the two 'a's.
"""

class Solution:
    def maxLengthBetweenEqualCharacters(self, s: str) -> int:
        firstIndex = {}
        ans = -1
        for i in range(len(s)):
            if s[i] in firstIndex:
                ans = max(ans, i - firstIndex[s[i]] - 1)
            else:
                firstIndex[s[i]] = i
        return ans