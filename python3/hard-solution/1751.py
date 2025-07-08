"""
1751. Maximum Number of Events That Can Be Attended II
    You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.
    You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.
    Return the maximum sum of values that you can receive by attending events.

    Example :
    Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
    Output: 7
    Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
"""

from typing import List
import bisect

class Solution:
    def maxValue(self, events: List[List[int]], k: int) -> int:
        events.sort()
        n = len(events)
        starts = [event[0] for event in events]
        ends = [event[1] for event in events]
        next_idx = []
        for i in range(n):
            next_i = bisect.bisect_right(starts, ends[i])
            next_idx.append(next_i)
        
        dp = [[0] * (n + 1) for _ in range(2)]
        for j in range(1, k + 1):
            cur = j % 2
            prev = (j - 1) % 2
            for i in range(n - 1, -1, -1):
                attend = events[i][2] + dp[prev][next_idx[i]]
                skip = dp[cur][i + 1]
                dp[cur][i] = max(attend, skip)
        return dp[k % 2][0]