"""
3863. Minimum Operations to Sort a String
    You are given a string s consisting of lowercase English letters.
    In one operation, you can select any substring of s that is not the entire string and sort it in non-descending alphabetical order.
    Return the minimum number of operations required to make s sorted in non-descending order. If it is not possible, return -1.

    Example :
    Input: s = "dog"
    Output: 1
    Explanation:
    Sort substring "og" to "go".
    Now, s = "dgo", which is sorted in ascending order. Thus, the answer is 1.
"""


from itertools import pairwise
class Solution:
    def minOperations(self, s: str) -> int:
        n = len(s)
        if n == 2 and s[0] > s[1]:
            return -1
        for ch1, ch2 in pairwise(s):
            if ch1 > ch2:
                break
        else:
            return 0
        mn, mx = min(s[1:-1]), max(s[1:-1])
        left, right = s[0], s[~0]
            
        if left <= min(right, mn) or right >= max(left, mx):
            return 1
        elif right >= mn or left <= mx:
            return 2
        else:
            return 3