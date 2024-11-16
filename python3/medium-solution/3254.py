"""
3254. Find the Power of K-Size Subarray
    You are given an array of integers nums of length n and a positive integer k.
    The power of an array is defined as:
    Its maximum element if all of its elements are consecutive and sorted in ascending order.
    -1 otherwise.
    You need to find the power of all 
    subarrays
    of nums of size k.
    Return an integer array results of size n - k + 1, where results[i] is the power of nums[i..(i + k - 1)].

    Example :
    Input: nums = [1,2,3,4,3,2,5], k = 3
    Output: [3,4,-1,-1,-1]
    Explanation:
    There are 5 subarrays of nums of size 3:
    [1, 2, 3] with the maximum element 3.
    [2, 3, 4] with the maximum element 4.
    [3, 4, 3] whose elements are not consecutive.
    [4, 3, 2] whose elements are not sorted.
    [3, 2, 5] whose elements are not consecutive.
"""

from typing import List
class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        n = len(nums)
        if n == 1 or k == 1:
            return nums
        ans = [-1] * (n - k + 1)
        cnt = 1
        for r in range(1, n):
            cnt = cnt + 1 if nums[r] == nums[r-1] + 1 else 1
            if cnt >= k:
                ans[r - k + 1] = nums[r]
        return ans