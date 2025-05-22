"""
3362. Zero Array Transformation III
    You are given an integer array nums of length n and a 2D array queries where queries[i] = [li, ri].
    Each queries[i] represents the following action on nums:
    Decrement the value at each index in the range [li, ri] in nums by at most 1.
    The amount by which the value is decremented can be chosen independently for each index.
    A Zero Array is an array with all its elements equal to 0.
    Return the maximum number of elements that can be removed from queries, such that nums can still be converted to a zero array using the remaining queries. If it is not possible to convert nums to a zero array, return -1.

    Example :
    Input: nums = [2,0,2], queries = [[0,2],[0,2],[1,1]]
    Output: 1
    Explanation:
    After removing queries[2], nums can still be converted to a zero array.
    Using queries[0], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
    Using queries[1], decrement nums[0] and nums[2] by 1 and nums[1] by 0.
"""


from typing import List
from collections import defaultdict
from heapq import heappop, heappush
class Solution:
    def maxRemoval(self, nums: List[int], queries: List[List[int]]) -> int:
        n = len(nums)
        edges = defaultdict(list)
        for start, end in queries:
            edges[start].append(end)

        lines = [0] * (n + 1)
        heap = []
        cur = 0
        for num_idx, num in enumerate(nums):
            if num_idx in edges:
                for end in edges[num_idx]:
                    heappush(heap, -end)
            cur += lines[num_idx]
            while cur < num:
                if not heap or -heap[0] < num_idx:
                    return -1
                end = -heappop(heap)
                cur += 1
                lines[end + 1] -= 1
        return len(heap)

        