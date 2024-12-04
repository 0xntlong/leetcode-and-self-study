"""
2825. Make String a Subsequence Using Cyclic Increments
    You are given two 0-indexed strings str1 and str2.
    In an operation, you select a set of indices in str1, and for each index i in the set, increment str1[i] to the next character cyclically. That is 'a' becomes 'b', 'b' becomes 'c', and so on, and 'z' becomes 'a'.
    Return true if it is possible to make str2 a subsequence of str1 by performing the operation at most once, and false otherwise.
    Note: A subsequence of a string is a new string that is formed from the original string by deleting some (possibly none) of the characters without disturbing the relative positions of the remaining characters.

    Example :
    Input: str1 = "abc", str2 = "ad"
    Output: true
    Explanation: Select index 2 in str1.
    Increment str1[2] to become 'd'. 
    Hence, str1 becomes "abd" and str2 is now a subsequence. Therefore, true is returned.
"""


class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
    # APPROACH 1 :
        idx = 0
        s2 = len(str2)
        for curr in str1:
            if idx < s2 and (ord(str2[idx]) - ord(curr)) % 26 < 2:
                idx += 1
        return idx == s2
        
        
        
        
        
    # APPROACH 2 :
        s1, s2 = len(str1), len(str2)
        target2 = str2[0]
        idx_str1 = idx_str2 = 0
        while idx_str1 < s1 and idx_str2 < s2:
            target1 = str1[idx_str1]
            if (target1 == target2 or chr(ord(target1) + 1) == target2 or
                (target1 == 'z' and target2 == 'a')):
                idx_str2 += 1
                if idx_str2 < s2:
                    target2 = str2[idx_str2]
            idx_str1 += 1
        return idx_str2 == s2