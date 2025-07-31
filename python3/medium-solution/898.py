"""
898. Bitwise ORs of Subarrays
    Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
    The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example :
    Input: arr = [0]
    Output: 1
    Explanation: There is only one possible result: 0.
"""

from typing import List
class Solution:
    def subarrayBitwiseORs(self, arr: List[int]) -> int:
        res = []
        s = 1
        for i in arr:
            n = len(res)
            res.append(i)
            for j in range(s, n):
                v = res[j] | i
                if (res[-1] != v):
                    res.append(v)
            s = n
        return len(set(res))