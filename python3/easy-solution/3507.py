"""
3507. Minimum Pair Removal to Sort Array I
    Given an array nums, you can perform the following operation any number of times:
    Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
    Replace the pair with their sum.
    Return the minimum number of operations needed to make the array non-decreasing.
    An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

    Example :
    Input: nums = [5,2,3,1]
    Output: 2
    Explanation:
    The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
    The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
    The array nums became non-decreasing in two operations.
"""


from typing import List
class Solution:
    def minimumPairRemoval(self, nums: List[int]) -> int:
        opt = 0
        def is_sorted(array):
            for i in range(1, len(array)):
                if array[i] < array[i - 1]:
                    return False
            return True
        while not is_sorted(nums):
            n = len(nums)
            min_sum = float('inf')
            idx = 0
            for i in range(n - 1):
                pair_sum = nums[i] + nums[i + 1]
                if pair_sum < min_sum:
                    min_sum = pair_sum
                    idx = i
            nums = nums[:idx] + [min_sum] + nums[idx + 2:]
            opt += 1
        return opt