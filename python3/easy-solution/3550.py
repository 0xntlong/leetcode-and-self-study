"""
3550. Smallest Index With Digit Sum Equal to Index
    You are given an integer array nums.
    Return the smallest index i such that the sum of the digits of nums[i] is equal to i.
    If no such index exists, return -1.
    Example :
    Input: nums = [1,3,2]
    Output: 2
    Explanation:
    For nums[2] = 2, the sum of digits is 2, which is equal to index i = 2. Thus, the output is 2.
"""


class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        ans = []

        for i in range(len(nums)):
            res = 0

            while nums[i] > 0:
                res += nums[i] % 10
                nums[i] //= 10

            if res == i:
                ans.append(i)

        ans.sort()

        if not ans:
            return -1
        else:
            return ans[0]