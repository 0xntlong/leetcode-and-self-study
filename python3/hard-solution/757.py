"""
757. Set Intersection Size At Least Two
    You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.
    A containing set is an array nums where each interval from intervals has at least two integers in nums.
    For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.
    Return the minimum possible size of a containing set.
    
    Example :
    Input: intervals = [[1,3],[3,7],[8,9]]
    Output: 5
    Explanation: let nums = [2, 3, 4, 8, 9].
    It can be shown that there cannot be any containing array of size 4.
"""

from typing import List

class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key = lambda x: (x[1], -x[0]))
        cnt = 2
        n = len(intervals)
        second = intervals[0][1]
        first = second - 1

        for i in range(1, n):
            left, right = intervals[i]
            if first >= left:
                continue
            new = left > second
            cnt += 1 + new 
            first = right - 1 if new else second
            second = right
        return cnt