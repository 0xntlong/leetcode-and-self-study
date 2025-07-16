"""
3201. Find the Maximum Length of Valid Subsequence I
    You are given an integer array nums.
    A subsequence sub of nums with length x is called valid if it satisfies:
    (sub[0] + sub[1]) % 2 == (sub[1] + sub[2]) % 2 == ... == (sub[x - 2] + sub[x - 1]) % 2.
    Return the length of the longest valid subsequence of nums.
    A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.

    Example :
    Input: nums = [1,2,3,4]
    Output: 4
    Explanation:
    The longest valid subsequence is [1, 2, 3, 4].

"""
from typing import List

class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        odd = 0
        even = 0
        count = 1
        prev = nums[0] % 2
        for i in nums:
            div = i % 2
            if div:
                even += 1
            else:
                odd += 1
            if prev != div:
                count += 1
            prev = div
        return max(odd, even, count)
