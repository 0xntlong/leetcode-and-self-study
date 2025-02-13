"""
3066. Minimum Operations to Exceed Threshold Value II
    You are given a 0-indexed integer array nums, and an integer k.
    In one operation, you will:
    Take the two smallest integers x and y in nums.
    Remove x and y from nums.
    Add min(x, y) * 2 + max(x, y) anywhere in the array.
    Note that you can only apply the described operation if nums contains at least two elements.
    Return the minimum number of operations needed so that all elements of the array are greater than or equal to k.

    Example :
    Input: nums = [2,11,10,1,3], k = 10
    Output: 2
    Explanation: In the first operation, we remove elements 1 and 2, then add 1 * 2 + 2 to nums. nums becomes equal to [4, 11, 10, 3].
    In the second operation, we remove elements 3 and 4, then add 3 * 2 + 4 to nums. nums becomes equal to [10, 11, 10].
    At this stage, all the elements of nums are greater than or equal to 10 so we can stop.
    It can be shown that 2 is the minimum number of operations needed so that all elements of the array are greater than or equal to 10.
"""

from typing import List
import heapq

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        pq = [num for num in nums if num < k]
        heapq.heapify(pq)

        operations = 0
        while pq:
            x = heapq.heappop(pq)
            operations += 1
            if not pq:
                break
        
            y = heapq.heappop(pq)
            new = x * 2 + y

            if new < k:
                heapq.heappush(pq, new)

        return operations