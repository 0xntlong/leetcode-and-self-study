"""
2054, Two Best Non-Overlapping Events 
    You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.
    Return this maximum sum.
    Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

    Example :
    Input: events = [[1,3,2],[4,5,2],[2,4,3]]
    Output: 4
    Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
"""

from typing import List
class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        n = len(events)
        events.sort(key = lambda x : x[0])
        suffix = [0] * n
        suffix[n - 1] = events[n - 1][2]
        for i in range(n-2, -1, -1):
            suffix[i] = max(events[i][2], suffix[i + 1])
        maxSum = 0
        for i in range(n):
            left, right = i + 1, n - 1
            nextEvent = -1
            while left <= right:
                mid = left + (right - left) // 2
                if events[mid][0] > events[i][1]:
                    nextEvent = mid
                    right = mid - 1
                else:
                    left = mid + 1
            if nextEvent != -1:
                maxSum = max(maxSum, events[i][2] + suffix[nextEvent])
            maxSum = max(maxSum, events[i][2])
        return maxSum            