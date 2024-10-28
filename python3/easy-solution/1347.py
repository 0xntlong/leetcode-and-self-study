"""
1347. Minimum Number of Steps to Make Two Strings Anagram
    Given an binary array nums and an integer k, return true if all 1's are at least k places away from each other, otherwise return false.
    
    Example :
    Input: nums = [1,0,0,0,1,0,0,1], k = 2
    Output: true
    Explanation: Each of the 1s are at least 2 places away from each other.
"""

from typing import List
class Solution:
    def kLengthApart(self, nums: List[int], k: int) -> bool:
        n = len(nums)
        j = -1
        for i in range(n):
            if nums[i]:
                if (i - j - 1 >= k) or (j == -1):
                    j = i
                else :
                    return False
        return True