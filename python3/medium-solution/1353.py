"""
1353. Maximum Number of Events That Can Be Attended
    You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.
    You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.
    Return the maximum number of events you can attend.

    Example :
    Input: events = [[1,2],[2,3],[3,4]]
    Output: 3
    Explanation: You can attend all the three events.
    One way to attend them all is as shown.
    Attend the first event on day 1.
    Attend the second event on day 2.
    Attend the third event on day 3.
"""


from typing import List
import heapq
class Solution:
    def maxEvents(self, events: List[List[int]]) -> int:
        events.sort()
        pq = []
        max_events = 0
        n = len(events)
        day = 1 
        i = 0
        while i < n or pq:
            if not pq and i < n:
                day = events[i][0]
                
            while i < n and events[i][0] <= day:
                heapq.heappush(pq, events[i][1])
                i += 1
            while pq and pq[0] < day:
                heapq.heappop(pq)
            if pq:
                heapq.heappop(pq)
                max_events += 1
            day += 1
        return max_events