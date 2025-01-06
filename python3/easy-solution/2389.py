"""
2389. Longest Subsequence With Limited Sum
    You are given an integer array nums of length n, and an integer array queries of length m.
    Return an array answer of length m where answer[i] is the maximum size of a subsequence that you can take from nums such that the sum of its elements is less than or equal to queries[i].
    A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

    Example :
    Input: nums = [4,5,2,1], queries = [3,10,21]
    Output: [2,3,4]
    Explanation: We answer the queries as follows:
    - The subsequence [2,1] has a sum less than or equal to 3. It can be proven that 2 is the maximum size of such a subsequence, so answer[0] = 2.
    - The subsequence [4,5,1] has a sum less than or equal to 10. It can be proven that 3 is the maximum size of such a subsequence, so answer[1] = 3.
    - The subsequence [4,5,2,1] has a sum less than or equal to 21. It can be proven that 4 is the maximum size of such a subsequence, so answer[2] = 4.
"""

from typing import List
from bisect import bisect_right

class Solution:
    def answerQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        nums.sort()
        n = len(nums)
        prefixSum = [0] * (n + 1)

        for i in range(1, n + 1):
            prefixSum[i] = prefixSum[i - 1] + nums[i - 1]
        res = []
        for query in queries:
            max_idx = bisect_right(prefixSum, query) - 1
            res.append(max_idx)
        return res