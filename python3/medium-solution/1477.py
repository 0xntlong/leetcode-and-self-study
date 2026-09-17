"""
1477. Find Two Non-overlapping Sub-arrays Each With Target Sum
    You are given an array of integers arr and an integer target.
    You have to find two non-overlapping sub-arrays of arr each with a sum equal target. There can be multiple answers so you have to find an answer where the sum of the lengths of the two sub-arrays is minimum.
    Return the minimum sum of the lengths of the two required sub-arrays, or return -1 if you cannot find such two sub-arrays.

    Example :
    Input: arr = [3,2,2,4,3], target = 3
    Output: 2
    Explanation: Only two sub-arrays have sum = 3 ([3] and [3]). The sum of their lengths is 2.
"""

from typing import List


class Solution:
    def minSumOfLengths(self, arr: List[int], target: int) -> int:
        n = len(arr)
        res, total, i = n + 1, 0, 0
        dp = [n] * (n + 1)

        for j in range(n):
            total += arr[j]

            while total > target:
                total -= arr[i]
                i += 1
                
            dp[j + 1] = dp[j]

            if total == target:
                Len = j - i + 1
                res = min(res, Len + dp[i])
                dp[j + 1] = min(dp[j], Len)
                
        return -1 if res == n + 1 else res