"""
2357. Make Array Zero by Subtracting Equal Amounts
    You are given a non-negative integer array nums. In one operation, you must:
    Choose a positive integer x such that x is less than or equal to the smallest non-zero element in nums.
    Subtract x from every positive element in nums.
    Return the minimum number of operations to make every element in nums equal to 0.

    Example :
    Input: nums = [1,5,0,3,5]
    Output: 3
    Explanation:
    In the first operation, choose x = 1. Now, nums = [0,4,0,2,4].
    In the second operation, choose x = 2. Now, nums = [0,2,0,0,2].
    In the third operation, choose x = 2. Now, nums = [0,0,0,0,0].
"""
from typing import List
import heapq
class Solution:
    def minimumOperations(self, nums: List[int]) -> int:
        heap = []
        for i in nums:
            if i != 0:
                heapq.heappush(heap, i)
        count = 0
        sub = 0
        while heap:
            current = heapq.heappop(heap)
            if current > sub:
                count += 1
                sub = current
        return count
