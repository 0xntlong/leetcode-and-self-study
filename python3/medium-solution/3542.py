"""
3542. Minimum Operations to Convert All Elements to Zero
    You are given an array nums of size n, consisting of non-negative integers. Your task is to apply some (possibly zero) operations on the array so that all elements become 0.
    In one operation, you can select a subarray [i, j] (where 0 <= i <= j < n) and set all occurrences of the minimum non-negative integer in that subarray to 0.
    Return the minimum number of operations required to make all elements in the array 0.

    Example 1:
    Input: nums = [0,2]
    Output: 1
    Explanation:
    Select the subarray [1,1] (which is [2]), where the minimum non-negative integer is 2. Setting all occurrences of 2 to 0 results in [0,0].
    Thus, the minimum number of operations required is 1.
"""


from typing import List
class Solution:
    def minOperations(self, nums: List[int]) -> int:
        stack = [-1]
        op = 0
        for i in nums:
            while stack and stack[-1] > i:
                stack.pop()
            if i > stack[-1]:
                op += (i > 0)
                stack.append(i)
        return op