"""
1590. Make Sum Divisible by P
    Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.
    Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.
    A subarray is defined as a contiguous block of elements in the array.

    Example :
    Input: nums = [3,1,4,2], p = 6
    Output: 1
    Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
"""


from typing import List
class Solution:
    def minSubarray(self, nums: List[int], p: int) -> int:
        total = sum(nums)
        target = total % p
        if target == 0:
            return 0
        prefix = 0
        n = len(nums)
        res = n
        dic = {0 : -1}
        cur = 0
        for i in range(n):
            cur = (cur + nums[i]) % p
            need = (cur - target) % p
            if need in dic:
                res = min(res, i - dic[need])
            dic[cur] = i
        return res if res < n else -1