"""
1043. Partition Array for Maximum Sum
    Given the array nums, obtain a subsequence of the array whose sum of elements is strictly greater than the sum of the non included elements in such subsequence. 
    If there are multiple solutions, return the subsequence with minimum size and if there still exist multiple solutions, return the subsequence with the maximum total sum of all its elements. A subsequence of an array can be obtained by erasing some (possibly zero) elements from the array. 
    Note that the solution with the given constraints is guaranteed to be unique. Also return the answer sorted in non-increasing order.

    Example :
    Input: nums = [4,3,10,9,8]
    Output: [10,9] 
    Explanation: The subsequences [10,9] and [10,8] are minimal such that the sum of their elements is strictly greater than the sum of elements not included. However, the subsequence [10,9] has the maximum total sum of its elements. 
"""

from typing import List
class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        nums.sort(reverse = True)
        N = len(nums)
        prefixSums = [0] * N
        prefixSums[0] = nums[0]
        for i in range(1, N):
            prefixSums[i] = prefixSums[i - 1] + nums[i]
        res = []
        totalSum = prefixSums[N - 1]
        for i in range(N):
            res.append(nums[i])
            subsequence = prefixSums[i]
            remain = totalSum - subsequence
            if subsequence > remain:
                break
        return res
            
