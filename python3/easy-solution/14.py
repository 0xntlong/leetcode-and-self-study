"""
14. Longest Common Prefix
    Write a function to find the longest common prefix string amongst an array of strings.
    If there is no common prefix, return an empty string "".
    
    Example:
    Input: strs = ["flower","flow","flight"]
    Output: "fl"
"""

class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs :
            return ""
        strs.sort()
        ans = ""
        first = strs[0]
        last = strs[-1]
        
        for i in range(min(len(first), len(last))):
            if(first[i]!=last[i]):
                return ans
            ans += first[i]
        return ans