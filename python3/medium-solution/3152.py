"""
3152. Special Array II 
    An array is considered special if every pair of its adjacent elements contains two numbers with different parity.
    You are given an array of integer nums and a 2D integer matrix queries, where for queries[i] = [fromi, toi] your task is to check that 
    subarray
    nums[fromi..toi] is special or not.
    Return an array of booleans answer such that answer[i] is true if nums[fromi..toi] is special.

    Example :
    Input: nums = [3,4,1,2,6], queries = [[0,4]]
    Output: [false]
    Explanation:
    The subarray is [3,4,1,2,6]. 2 and 6 are both even.
"""

from typing import List
class Solution:
    def isArraySpecial(self, nums: List[int], queries: List[List[int]]) -> List[bool]:
        n = len(nums)
        prefix = [0] * n
        ans = []
        for i in range(1, n):
            prefix[i] = prefix[i -1]
            if nums[i] % 2 == nums[i - 1] % 2:
                prefix[i] += 1
        for query in queries:
            from_i , to_i = query[0], query[1]
            not_special = prefix[to_i] - (prefix[from_i] if from_i > 0 else 0)
            if not_special and from_i != to_i:
                ans.append(False)
            else:
                ans.append(True)
        return ans