"""
3719. Longest Balanced Subarray I
    You are given an integer array nums.
    A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.
    Return the length of the longest balanced subarray.

    Example :
    Input: nums = [2,5,4,3]
    Output: 4
    Explanation:
    The longest balanced subarray is [2, 5, 4, 3].
    It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [5, 3]. Thus, the answer is 4.
"""

from typing import List
    
class Solution:
    def longestBalanced(self, nums: List[int]) -> int:
        n = len(nums)
        res = 0
        visited = set()
        for i in range(n):
            visited.clear()
            balance = 0
            if res > n - i:
                break
            for j in range(i, n):
                num = nums[j]
                if num not in visited:
                    if num % 2:
                        balance -= 1
                    else:
                        balance += 1
                    visited.add(num)
                if balance == 0:
                    res = max(res, j - i + 1)
        return res