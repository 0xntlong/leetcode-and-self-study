"""
1980. Find Unique Binary String
    Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.
    Example :
    Input: nums = ["01","10"]
    Output: "11"
    Explanation: "11" does not appear in nums. "00" would also be correct.
"""

from typing import List
class Solution:
    def findDifferentBinaryString(self, nums: List[str]) -> str:
        res = []
        for i in range(len(nums)):
            if (nums[i][i] == '0'):
                res.append('1')
            else:
                res.append('0')
        return ''.join(res)