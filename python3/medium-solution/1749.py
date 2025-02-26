"""
1749. Maximum Absolute Sum of Any Subarray
    You are given an integer array nums. The absolute sum of a subarray [numsl, numsl+1, ..., numsr-1, numsr] is abs(numsl + numsl+1 + ... + numsr-1 + numsr).
    Return the maximum absolute sum of any (possibly empty) subarray of nums.
    Note that abs(x) is defined as follows:
    If x is a negative integer, then abs(x) = -x.
    If x is a non-negative integer, then abs(x) = x.
    
    Example 1:
    Input: nums = [1,-3,2,3,-4]
    Output: 5
    Explanation: The subarray [2,3] has absolute sum = abs(2+3) = abs(5) = 5.
"""

from typing import List
from itertools import accumulate
class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        s = list(accumulate(nums, initial = 0))
        return max(s) - min(s)
    

# Another solution
from typing import List
class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        maxSum = 0
        minSum = 0
        for i in nums:
            maxSum = max(0, maxSum + i)
            minSum = min(0, minSum + i)
        return maxSum - minSum