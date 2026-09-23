"""
1658. Minimum Operations to Reduce X to Zero
    You are given an integer array nums and an integer x. In one operation, you can either remove the leftmost or the rightmost element from the array nums and subtract its value from x. Note that this modifies the array for future operations.
    Return the minimum number of operations to reduce x to exactly 0 if it is possible, otherwise, return -1.
    Example :
    Input: nums = [1,1,4,2,3], x = 5
    Output: 2
    Explanation: The optimal solution is to remove the last two elements to reduce x to zero.
"""


from typing import list
class Solution:
    def minOperations(self, nums: list[int], x: int) -> int:
        total = sum(nums)
        rmd = total - x

        if rmd < 0:
            return -1

        l = 0
        current_sum = 0
        maxlen = -1

        for r in range(len(nums)):
            current_sum += nums[r]

            while current_sum > rmd and l <= r:
                current_sum -= nums[l]
                l += 1

            if current_sum == rmd:
                maxlen = max(maxlen, r - l + 1)

        if maxlen == -1:
            return -1

        return len(nums) - maxlen