"""
1524. Number of Sub-arrays With Odd Sum
    Given an array of integers arr, return the number of subarrays with an odd sum.
    Since the answer can be very large, return it modulo 109 + 7.

    Example :
    Input: arr = [1,3,5]
    Output: 4
    Explanation: All subarrays are [[1],[1,3],[1,3,5],[3],[3,5],[5]]
    All sub-arrays sum are [1,4,9,3,8,5].
    Odd sums are [1,9,3,5] so the answer is 4.
"""

from typing import List
class Solution:
    def numOfSubarrays(self, arr: List[int]) -> int:
        MOD = 10**9 + 7
        odd = 0
        even = 1
        prefix_sum = 0
        res = 0
        for i in arr:
            prefix_sum += i
            if prefix_sum % 2 == 0:
                res = (res + odd) % MOD
                even += 1
            else :
                res = (res + even) % MOD
                odd += 1
        return res