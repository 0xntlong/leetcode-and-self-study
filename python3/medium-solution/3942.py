"""
3942. Minimum Operations to Sort a Permutation
    You are given an integer array nums of length n, where nums is a permutation of the integers from 0 to n - 1.
    You may perform only the following operations:
    Reverse the entire array.
    Rotate Left by One: Move the first element to the end of the array, and rest elements to left by one position.
    Return an integer denoting the minimum number of operations required to sort the array in increasing order. If it is not possible to sort the array using only the given operations, return -1.
    Example :
    Input: nums = [0,2,1]
    Output: 2
    Explanation:
    Rotate Left by one: [2, 1, 0]
    Reverse the array: [0, 1, 2]
    The array becomes sorted in 2 operations, which is minimal
"""


from typing import List
    
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return -1
        
        res = float('inf')
        target = list(range(n))

        k = nums.index(0)

        if nums[k:] + nums[:k] == target:
            res = min(res, k, n - k + 2)

        rev_nums = nums[::-1]
        k_rev = rev_nums.index(0)

        if rev_nums[k_rev:] + rev_nums[:k_rev] == target:
            res = min(res, k_rev + 1, n - k_rev + 1)

        if res == float('inf'):
            return -1
        
        return int(res)