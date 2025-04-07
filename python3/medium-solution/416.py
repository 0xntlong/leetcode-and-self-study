"""
416. Partition Equal Subset Sum
    Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
    Example :
    Input: nums = [1,5,11,5]
    Output: true
    Explanation: The array can be partitioned as [1, 5, 5] and [11].
"""


class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        total = sum(nums)
        if total % 2 != 0:
            return False
        mid = total // 2
        dp = [False] * (mid + 1)
        dp[0] = True
        for num in nums:
            for i in range(mid, num - 1, -1):
                dp[i] = dp[i] or dp[i - num]
            if dp[mid]:
                return True
        return dp[mid]