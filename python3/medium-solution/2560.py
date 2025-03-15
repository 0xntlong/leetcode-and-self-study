"""
2560. House Robber IV
    There are several consecutive houses along a street, each of which has some money inside. There is also a robber, who wants to steal money from the homes, but he refuses to steal from adjacent homes.
    The capability of the robber is the maximum amount of money he steals from one house of all the houses he robbed.
    You are given an integer array nums representing how much money is stashed in each house. More formally, the ith house from the left has nums[i] dollars.
    You are also given an integer k, representing the minimum number of houses the robber will steal from. It is always possible to steal at least k houses.
    Return the minimum capability of the robber out of all the possible ways to steal at least k houses.

    Example :
    Input: nums = [2,3,5,9], k = 2
    Output: 5
    Explanation: 
    There are three ways to rob at least 2 houses:
    - Rob the houses at indices 0 and 2. Capability is max(nums[0], nums[2]) = 5.
    - Rob the houses at indices 0 and 3. Capability is max(nums[0], nums[3]) = 9.
    - Rob the houses at indices 1 and 3. Capability is max(nums[1], nums[3]) = 9.
    Therefore, we return min(5, 9, 9) = 5.
"""

from typing import List
class Solution:
    def minCapability(self, nums: List[int], k: int) -> int:
        n = len(nums)
        minH = min(nums)
        maxH = max(nums)
        def money(capability):
            steal, j = 0, 0
            while j < n and steal < k:
                if nums[j] <= capability:
                    steal += 1
                    j += 1
                j += 1
            return steal >= k
        
        left, right = minH, maxH
        while left < right:
            mid = (left + right) >> 1
            if money(mid):
                right = mid
            else:
                left = mid + 1
        return left