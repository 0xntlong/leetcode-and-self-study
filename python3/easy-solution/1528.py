"""
1528. Shuffle String
    Given a string s and an integer array indices of the same length.
    The string s will be shuffled such that the character at the ith position moves to indices[i] in the shuffled string.
    Return the shuffled string.

    Example:
    Input: s = "codeleet", indices = [4,5,6,7,0,2,1,3]
    Output: "leetcode"
    Explanation: As shown, "codeleet" becomes "leetcode" after shuffling.
"""

from typing import List
class Solution:
    def restoreString(self, s: str, indices: List[int]) -> str:
        n = len(s)
        ans = [''] * n
        for i in range(n):
            shuffle = indices[i]
            ans[shuffle] = s[i]
        return ''.join(ans)