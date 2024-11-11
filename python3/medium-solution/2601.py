"""
2601. Prime Subsraction Operation
    You are given a 0-indexed integer array nums of length n.
    You can perform the following operation as many times as you want:
    Pick an index i that you have not picked before, and pick a prime p strictly less than nums[i], then subtract p from nums[i].
    Return true if you can make nums a strictly increasing array using the above operation and false otherwise.
    A strictly increasing array is an array whose each element is strictly greater than its preceding element.

    Example :
    Input: nums = [4,9,6,10]
    Output: true
    Explanation: In the first operation: Pick i = 0 and p = 3, and then subtract 3 from nums[0], so that nums becomes [1,9,6,10].
    In the second operation: i = 1, p = 7, subtract 7 from nums[1], so nums becomes equal to [1,2,6,10].
    After the second operation, nums is sorted in strictly increasing order, so the answer is true.
"""

from typing import List
class Solution:
        def primeSubOperation(self, nums: List[int]) -> bool:
            def max_element(nums):
                return max(nums)
            maxElement = max_element(nums)
            marked = [True] * (maxElement + 1)
            marked[1] = False

            for i in range(2, int ((maxElement + 1) ** 0.5) + 1):
                if marked[i]:
                    for j in range( i * i, maxElement + 1, i):
                        marked[j] = False
            
            currVal, i = 1, 0
            while i < len(nums):
                diff = nums[i] - currVal
                if diff < 0:
                    return False
                if marked[diff] == True or diff == 0:
                    i += 1
                    currVal += 1
                else:
                    currVal += 1
            return True
        