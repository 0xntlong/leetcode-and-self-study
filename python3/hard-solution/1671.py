"""
1671. Minimum Number of Removals to Make Mountain Array
    You may recall that an array arr is a mountain array if and only if:
    arr.length >= 3
    There exists some index i (0-indexed) with 0 < i < arr.length - 1 such that:
    arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
    Given an integer array nums​​​, return the minimum number of elements to remove to make nums​​​ a mountain array.

    Example :
    Input: nums = [1,3,1]
    Output: 0
    Explanation: The array itself is a mountain array so we do not need to remove any elements.
"""


import bisect
from typing import List


#First Solution
class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        N = len(nums)
        LIS = [1] * N
        for i in range(1, N):
            for j in range(i):
                if nums[i] > nums[j]:
                    LIS[i] = max(LIS[i], LIS[j] +1)
        LDS = [1] * N
        for i in range(N - 2, -1, -1):
            for j in range(i + 1, N):
                if nums[i] > nums[j]:
                    LDS[i] = max(LDS[i], LDS[j] + 1)
        minimum = N
        for i in range(1 , N - 1):
            if LIS[i] > 1 and LDS[i] > 1:
                minimum = min(minimum, N - (LIS[i] + LDS[i] - 1))
        return minimum


# Second Solution   
class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        N = len(nums)
        INF = 10 ** 20
        
        def LIS(nums):
            ans = []
            smallest = [-INF]
            for i in nums:
                idx = bisect.bisect_left(smallest, i)
                if idx >= len(smallest):
                    smallest.append(INF)
                smallest[idx] = min(smallest[idx], i)
                ans.append(idx)
            return ans
        left_side = LIS(nums)
        right_side = LIS(nums[::-1])[::-1]
        minimum = 0
        for i in range(N):
            if left_side[i] > 1 and right_side[i] > 1:
                minimum = max(minimum, left_side[i] + right_side[i] -1)
        return N - minimum