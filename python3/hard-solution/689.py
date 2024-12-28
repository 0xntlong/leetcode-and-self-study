"""
689. Maximum Sum of 3 Non-Overlapping Subarrays
    Given an integer array nums and an integer k, find three non-overlapping subarrays of length k with maximum sum and return them.
    Return the result as a list of indices representing the starting position of each interval (0-indexed). If there are multiple answers, return the lexicographically smallest one.

    Example :
    Input: nums = [1,2,1,2,6,7,5,1], k = 2
    Output: [0,3,5]
    Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
    We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
"""

from typing import List
class Solution:
    def maxSumOfThreeSubarrays(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        sum_k = [0] * (n - k + 1)
        left = [-1] * (n - 3 * k + 1)
        sum_k[0] = sum(nums[:k])
        for i in range(1, n - k + 1):
            sum_k[i] = sum_k[i - 1] - nums[i - 1] + nums[i + k - 1]
        max_k = sum_k[0]
        left[0] = 0
        for i in range(1, len(left)):
            if max_k < sum_k[i]:
                max_k = sum_k[i]
                left[i] = i
            else:
                left[i] = left[i - 1]
        right = [-1] * len(left)
        max_k = sum_k[-1]
        right[-1] = len(sum_k) -1
        for i in range(len(sum_k) - 2, 2 * k - 1, -1):
            if max_k <= sum_k[i]:
                max_k = sum_k[i]
                right[i - 2 * k] = i
            else:
                right[i - 2 * k] = right[i + 1 - 2 * k]
        res = [-1, -1 ,-1]
        max_3k = 0
        for i in range(len(left)):
            mid = i + k
            if mid >= len(sum_k) or right[i] == -1:
                continue
            sum_3k = sum_k[left[i]] + sum_k[mid] + sum_k[right[i]]
            if sum_3k > max_3k:
                max_3k = sum_3k
                res = [left[i], mid, right[i]]
        return res