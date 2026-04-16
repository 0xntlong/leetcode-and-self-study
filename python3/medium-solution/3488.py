"""
3488. Closest Equal Element Queries
    You are given a circular array nums and an array queries.
    For each query i, you have to find the following:
    The minimum distance between the element at index queries[i] and any other index j in the circular array, where nums[j] == nums[queries[i]]. If no such index exists, the answer for that query should be -1.
    Return an array answer of the same size as queries, where answer[i] represents the result for query i.
    Example :
    Input: nums = [1,3,1,4,1,3,2], queries = [0,3,5]
    Output: [2,-1,3]
    Explanation:
    Query 0: The element at queries[0] = 0 is nums[0] = 1. The nearest index with the same value is 2, and the distance between them is 2.
    Query 1: The element at queries[1] = 3 is nums[3] = 4. No other index contains 4, so the result is -1.
    Query 2: The element at queries[2] = 5 is nums[5] = 3. The nearest index with the same value is 1, and the distance between them is 3 (following the circular path: 5 -> 6 -> 0 -> 1).
"""


from typing import List
class Solution:
    def solveQueries(self, nums: List[int], queries: List[int]) -> List[int]:
        n = len(nums)
        last = {}       
        dp = [n] * n

        for i in range(n * 2):
            idx = i % n
            num = nums[idx]

            if num in last:
                prev = last[num]
                dist = i - prev

                dp[idx] = min(dp[idx], dist)
                dp[prev % n] = min(dp[prev % n], dist)

            last[num] = i

        return [-1 if dp[q] == n else dp[q] for q in queries]