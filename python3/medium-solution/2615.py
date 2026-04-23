"""
2615. Sum of Distances
    You are given a 0-indexed integer array nums. There exists an array arr of length nums.length, where arr[i] is the sum of |i - j| over all j such that nums[j] == nums[i] and j != i. If there is no such j, set arr[i] to be 0.
    Return the array arr.
    Example :
    Input: nums = [1,3,1,1,2]
    Output: [5,0,3,4,0]
    Explanation: 
    When i = 0, nums[0] == nums[2] and nums[0] == nums[3]. Therefore, arr[0] = |0 - 2| + |0 - 3| = 5. 
    When i = 1, arr[1] = 0 because there is no other index with value 3.
    When i = 2, nums[2] == nums[0] and nums[2] == nums[3]. Therefore, arr[2] = |2 - 0| + |2 - 3| = 3. 
    When i = 3, nums[3] == nums[0] and nums[3] == nums[2]. Therefore, arr[3] = |3 - 0| + |3 - 2| = 4. 
    When i = 4, arr[4] = 0 because there is no other index with value 2. 
"""

from collections import defaultdict
from typing import List
    
class Solution:
    def distance(self, nums: List[int]) -> List[int]:
        d = defaultdict(list)
        for i, val in enumerate(nums):
            d[val].append(i)
        res = [0] * len(nums)
        for v in d.values():
            if len(v) > 1:
                c = len(v)
                i = v[0]
                res[i] = sum(v) - c * i
                x, y = 0, c - 2
                for n in v[1:]:
                    res[n] = res[i] + (x - y) * (n - i)
                    x += 1
                    y -= 1
                    i = n
        return res 