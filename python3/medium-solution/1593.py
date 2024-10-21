"""
1593. Split a String Into the Max Number of Unique Substrings
    Given a string s, return the maximum number of unique substrings that the given string can be split into.
    You can split string s into any list of non-empty substrings, where the concatenation of the substrings forms the original string. However, you must split the substrings such that all of them are unique.
    A substring is a contiguous sequence of characters within a string.

    Example:
    Input: s = "ababccc"
    Output: 5
    Explanation: One way to split maximally is ['a', 'b', 'ab', 'c', 'cc']. Splitting like ['a', 'b', 'a', 'b', 'c', 'cc'] is not valid as you have 'a' and 'b' multiple times.
"""

class Solution:
    def maxUniqueSplit(self, s: str) -> int:
        def DFS(i, hash_set):
            if i == len(s):
                return 0
            result = 0
            for j in range(i + 1, len(s) + 1):
                substr = s[i:j] 
                if substr not in hash_set:
                    hash_set.add(substr)
                    result = max(result, 1 + DFS(j, hash_set))
                    hash_set.remove(substr)
            return result

        return DFS(0, set())