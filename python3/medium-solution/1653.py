"""
1653. Minimum Deletions to Make String Balanced
    You are given a string s consisting only of characters 'a' and 'b'​​​​.
    You can delete any number of characters in s to make s balanced. s is balanced if there is no pair of indices (i,j) such that i < j and s[i] = 'b' and s[j]= 'a'.
    Return the minimum number of deletions needed to make s balanced.

    Example :
    Input: s = "aababbab"
    Output: 2
    Explanation: You can either:
    Delete the characters at 0-indexed positions 2 and 6 ("aababbab" -> "aaabbb"), or
    Delete the characters at 0-indexed positions 3 and 6 ("aababbab" -> "aabbbb").
"""



class Solution:
    def minimumDeletions(self, s: str) -> int:
        res = 0
        count = 0
        for c in s:
            if c == 'b':
                count += 1
            else:
                if count > 0:
                    res += 1
                    count -= 1
        return res