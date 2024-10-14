"""
This file is a minimal set of MEDIUM solutions to leetcode problems in Python3.
No algorithms or reasoning are provided to save space.
For more details, readers are suggested to explore on their own or search on Threads platform : leetcodedaybyday . Thanks for reading.
"""
from typing import List
import heapq
import math
class Solution:
    """
    2530. Maximal Score After Applying K Operations
    You are given a 0-indexed integer array nums and an integer k. You have a starting score of 0.
    In one operation:
    choose an index i such that 0 <= i < nums.length,
    increase your score by nums[i], and
    replace nums[i] with ceil(nums[i] / 3).
    Return the maximum possible score you can attain after applying exactly k operations.
    The ceiling function ceil(val) is the least integer greater than or equal to val.

    Example 1:
    Input: nums = [10,10,10,10,10], k = 5
    Output: 50
    Explanation: Apply the operation to each array element exactly once. The final score is 10 + 10 + 10 + 10 + 10 = 50.
    """
    def maxKelements(self, nums: List[int], k: int) -> int:
        res = 0
        max_heap = [-n for n in nums]
        heapq.heapify(max_heap)
        while k:
            n = -heapq.heappop(max_heap)
            res += n
            k -= 1
            heapq.heappush(max_heap, -math.ceil(n / 3))
        return res
    
