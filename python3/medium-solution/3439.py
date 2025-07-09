"""
3439. Reschedule Meetings for Maximum Free Time I
    You are given an integer eventTime denoting the duration of an event, where the event occurs from time t = 0 to time t = eventTime.
    You are also given two integer arrays startTime and endTime, each of length n. These represent the start and end time of n non-overlapping meetings, where the ith meeting occurs during the time [startTime[i], endTime[i]].
    You can reschedule at most k meetings by moving their start time while maintaining the same duration, to maximize the longest continuous period of free time during the event.
    The relative order of all the meetings should stay the same and they should remain non-overlapping.
    Return the maximum amount of free time possible after rearranging the meetings.
    Note that the meetings can not be rescheduled to a time outside the event.

    Example:
    Input: eventTime = 5, k = 1, startTime = [1,3], endTime = [2,5]
    Output: 2
    Explanation:
    Reschedule the meeting at [1, 2] to [2, 3], leaving no meetings during the time [0, 2].
"""

from typing import List
class Solution:
    def maxFreeTime(self, eventTime: int, k: int, startTime: List[int], endTime: List[int]) -> int:
        n = len(startTime)
        gap = [0] * (n + 1)
        gap[0] = startTime[0]
        gap[n] = eventTime - endTime[-1]
        for i in range(1, n):
            gap[i] = startTime[i] - endTime[i - 1]

        total = sum(gap[:k + 1])
        res = total

        for i in range(k + 1, n + 1):
            total += gap[i] - gap[i - (k + 1)]
            res = max(res, total)

        return res