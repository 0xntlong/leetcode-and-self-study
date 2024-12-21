"""
2164. Sort Even Indices Independently
    You are given a 0-indexed integer array nums. Rearrange the values of nums according to the following rules:
    Sort the values at odd indices of nums in non-increasing order.
    For example, if nums = [4,1,2,3] before this step, it becomes [4,3,2,1] after. The values at odd indices 1 and 3 are sorted in non-increasing order.
    Sort the values at even indices of nums in non-decreasing order.
    For example, if nums = [4,1,2,3] before this step, it becomes [2,1,4,3] after. The values at even indices 0 and 2 are sorted in non-decreasing order.
    Return the array formed after rearranging the values of nums.

    Example :
    Input: nums = [4,1,2,3]
    Output: [2,3,4,1]
    Explanation: 
    First, we sort the values present at odd indices (1 and 3) in non-increasing order.
    So, nums changes from [4,1,2,3] to [4,3,2,1].
    Next, we sort the values present at even indices (0 and 2) in non-decreasing order.
    So, nums changes from [4,1,2,3] to [2,3,4,1].
    Thus, the array formed after rearranging the values is [2,3,4,1].
"""

from typing import List
class Solution:
    def sortEvenOdd(self, nums: List[int]) -> List[int]:
        n = len(nums)
        odd = []
        even = []
        for i in range(n):
            if i % 2 == 0:
                even.append(nums[i])
            else:
                odd.append(nums[i])
        even.sort()
        odd.sort(reverse=True)
        i, j = 0, 0
        for k in range(n):
            if k % 2 == 0:
                nums[k] = even[i]
                i += 1
            else:
                nums[k] = odd[j]
                j += 1
        return nums 