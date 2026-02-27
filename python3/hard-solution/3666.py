"""
3666. Minimum Operations to Equalize Binary String
    You are given a binary string s, and an integer k.
    In one operation, you must choose exactly k different indices and flip each '0' to '1' and each '1' to '0'.
    Return the minimum number of operations required to make all characters in the string equal to '1'. If it is not possible, return -1.

    Example :
    Input: s = "110", k = 1
    Output: 1
    Explanation:
    There is one '0' in s.
    Since k = 1, we can flip it directly in one operation.

"""


from math import inf

class Solution:
    def minOperations(self, s: str, k: int) -> int:
        n = len(s)
        zero = s.count('0')
        if n == k:
            if zero == 0:
                return 0
            elif zero == n:
                return 1
            else:
                return -1
        
        def ceil(x, y):
            return (x + y - 1) // y
        
        res = inf
        
        if zero % 2 == 0:
            m = max(ceil(zero, k), ceil(zero, n - k))
            if m % 2 == 1:
                m += 1
            res = min(res, m)
        if zero % 2 == k % 2:
            m = max(ceil(zero, k), ceil(n - zero, n - k))
            if m % 2 == 0:
                m += 1
            res = min(res, m)
            
        return res if res < inf else -1