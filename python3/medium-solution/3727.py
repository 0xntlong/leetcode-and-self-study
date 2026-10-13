"""
3727. Maximum Alternating Sum of Squares
    You are given an integer array nums. You may rearrange the elements in any order.
    The alternating score of an array arr is defined as:
    score = arr[0]2 - arr[1]2 + arr[2]2 - arr[3]2 + ...
    Return an integer denoting the maximum possible alternating score of nums after rearranging its elements.
    Example :
    Input: nums = [1,2,3]
    Output: 1
    Explanation:
    A possible rearrangement for nums is [2,1,3], which gives the maximum alternating score among all possible rearrangements.
    The alternating score is calculated as:
    score = 22 - 12 + 32 = 4 - 1 + 9 = 12
"""


from typing import List
class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        n = len(nums)
        h = n // 2

        nums = sorted(abs(x) for x in nums)

        ans = 0
        for i in range(n):
            ans += (-1 if i < h else 1) * nums[i] * nums[i]

        return ans