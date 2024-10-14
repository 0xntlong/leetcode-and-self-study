"""
This file is a minimal set of HARD solutions to leetcode problems in Python3.
No algorithms or reasoning are provided to save space.
For more details, readers are suggested to explore on their own or search on Threads platform : leetcodedaybyday . Thanks for reading.
"""
from collections import defaultdict
from typing import List

class Solution:
    """
    632. Smallest Range Covering Elements from K Lists
    You have k lists of sorted integers in non-decreasing order. Find the smallest range that includes at least one number from each of the k lists.
    We define the range [a, b] is smaller than range [c, d] if b - a < d - c or a < c if b - a == d - c.
    
    Example:
    Input: nums = [[4,10,15,24,26],[0,9,12,20],[5,18,22,30]]
    Output: [20,24]
    Explanation: 
    List 1: [4, 10, 15, 24,26], 24 is in range [20,24].
    List 2: [0, 9, 12, 20], 20 is in range [20,24].
    List 3: [5, 18, 22, 30], 22 is
    """
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        List = []
        for k, num_list in enumerate(nums):
            for n in num_list:
                List.append((n, k))
        List.sort()
        i, k = 0, 0
        ans = []
        count = defaultdict(int)
        for j in range(len(List)):
            if count[List[j][1]] == 0:
                k += 1
            count[List[j][1]] += 1

            if k == len(nums):
                while count[List[i][1]] > 1:
                    count[List[i][1]] -= 1
                    i += 1
                if not ans or ans[1] - ans[0] > List[j][0] - List[i][0]:
                    ans = [List[i][0], List[j][0]]
        return ans