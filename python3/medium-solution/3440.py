"""
3440. Reschedule Meetings for Maximum Free Time II
    You are given an integer eventTime denoting the duration of an event. You are also given two integer arrays startTime and endTime, each of length n.
    These represent the start and end times of n non-overlapping meetings that occur during the event between time t = 0 and time t = eventTime, where the ith meeting occurs during the time [startTime[i], endTime[i]].
    You can reschedule at most one meeting by moving its start time while maintaining the same duration, such that the meetings remain non-overlapping, to maximize the longest continuous period of free time during the event.
    Return the maximum amount of free time possible after rearranging the meetings.
    Note that the meetings can not be rescheduled to a time outside the event and they should remain non-overlapping.
    Note: In this version, it is valid for the relative ordering of the meetings to change after rescheduling one meeting.

    Example 1:
    Input: eventTime = 5, startTime = [1,3], endTime = [2,5]
    Output: 2
    Explanation:
    Reschedule the meeting at [1, 2] to [2, 3], leaving no meetings during the time [0, 2].
"""


from typing import List

class Solution:
    def maxFreeTime(self, eventTime: int, startTime: List[int], endTime: List[int]) -> int:
        n = len(startTime)
        gap = [0] * (n + 1)
        lastEnd = 0
        for i in range(n):
            gap[i] = startTime[i] - lastEnd
            lastEnd = endTime[i]
        
        gap[n] = eventTime - lastEnd
        rightMax = [0] * (n + 1)
        for i in range(n - 1, - 1, -1):
            rightMax[i] = max(rightMax[i + 1], gap[i + 1])
        
        leftMax = 0
        maxGap = 0
        for i in range(1, n + 1):
            dur = endTime[i - 1] - startTime[i - 1]
            gapL = gap[i - 1]
            gapR = gap[i]

            if leftMax >= dur or rightMax[i] >= dur:
                maxGap = max(maxGap, gapL + dur + gapR)
            maxGap = max(maxGap, gapL + gapR)
            leftMax = max(leftMax, gapL)
        return maxGap