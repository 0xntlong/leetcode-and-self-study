"""
3886. Sum of Sortable Integers
    You are given an integer array nums of length n.
    An integer k is called sortable if k divides n and you can sort nums in non-decreasing order by sequentially performing the following operations:
    Partition nums into consecutive subarrays of length k.
    Cyclically rotate each subarray independently any number of times to the left or to the right.
    Return an integer denoting the sum of all possible sortable integers k.

    Example :
    Input: nums = [3,1,2]
    Output: 3
    Explanation:
    For n = 3, possible divisors are 1 and 3.
    For k = 1: each subarray has one element. No rotation can sort the array.
    For k = 3: the single subarray [3, 1, 2] can be rotated once to produce [1, 2, 3], which is sorted.
    Only k = 3 is sortable. Hence, the answer is 3.
"""
from typing import List
import math

class Solution:
    def sortableIntegers(self, nums: List[int]) -> int:
        if not nums:
            return 0

        N = len(nums)
        
        divisors = []
        for i in range(1, int(math.sqrt(N))+1):
            if N%i == 0:
                divisors.append(i)
                if N//i != i:
                    divisors.append(N//i)
        
        
        answer = 0
        for d in divisors:
            r = 0
            l = 0
            valid = True

            prev_max = float("-inf")
            while r < len(nums):
                start = r
                r += d

                drops = 0
                curr_max = float("-inf")
                curr_min = float("inf")
                
                while l < r:
                    if l+1 < r and nums[l] > nums[l+1]:
                        if drops < 1 and nums[start] >= nums[r-1]:
                            drops+=1
                        else:
                            valid = False
                            break
                    curr_min = min(curr_min, nums[l])
                    curr_max = max(curr_max, nums[l])
                    l+=1
                if not valid:
                    break

                if curr_min < prev_max:
                    valid = False
                    break

                prev_max = curr_max

            if valid:
                answer += d

        return answer