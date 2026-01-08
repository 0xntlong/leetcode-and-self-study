"""
1458. Max Dot Product of Two Subsequences
    Given two arrays nums1 and nums2.
    Return the maximum dot product between non-empty subsequences of nums1 and nums2 with the same length.
    A subsequence of a array is a new array which is formed from the original array by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, [2,3,5] is a subsequence of [1,2,3,4,5] while [1,5,3] is not).

    Example :
    Input: nums1 = [2,1,-2,5], nums2 = [3,0,-6]
    Output: 18
    Explanation: Take subsequence [2,-2] from nums1 and subsequence [3,-6] from nums2.
    Their dot product is (2*3 + (-2)*(-6)) = 18.
"""

from typing import List
class Solution:
    def maxDotProduct(self, nums1: List[int], nums2: List[int]) -> int:
        if nums1[0] > nums2[0]:
            nums2 , nums1 = nums1, nums2
        if max(nums1) < 0 and min(nums2) > 0:
            return max(nums1) * min(nums2)
        m, n = len(nums1), len(nums2)
        dp = [0] * (n + 1)
        for i in range(m):
            for j in range(n - 1, -1, -1):
                v = nums1[i] * nums2[j] + dp[j]
                if v > dp[j + 1]:
                    dp[j + 1] = v
            for j in range(n):
                if dp[j + 1] < dp[j]:
                    dp[j + 1] = dp[j]
        return dp[j + 1]