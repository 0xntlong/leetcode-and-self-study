"""
2402. Meeting Rooms III
    You are given an integer n. There are n rooms numbered from 0 to n - 1.

    You are given a 2D integer array meetings where meetings[i] = [starti, endi] means that a meeting will be held during the half-closed time interval [starti, endi). All the values of starti are unique.

    Meetings are allocated to rooms in the following manner:

    Each meeting will take place in the unused room with the lowest number.
    If there are no available rooms, the meeting will be delayed until a room becomes free. The delayed meeting should have the same duration as the original meeting.
    When a room becomes unused, meetings that have an earlier original start time should be given the room.
    Return the number of the room that held the most meetings. If there are multiple rooms, return the room with the lowest number.

    A half-closed interval [a, b) is the interval between a and b including a and not including b.

    

    Example :

    Input: n = 2, meetings = [[0,10],[1,5],[2,7],[3,4]]
    Output: 0
    Explanation:
    - At time 0, both rooms are not being used. The first meeting starts in room 0.
    - At time 1, only room 1 is not being used. The second meeting starts in room 1.
    - At time 2, both rooms are being used. The third meeting is delayed.
    - At time 3, both rooms are being used. The fourth meeting is delayed.
    - At time 5, the meeting in room 1 finishes. The third meeting starts in room 1 for the time period [5,10).
    - At time 10, the meetings in both rooms finish. The fourth meeting starts in room 0 for the time period [10,11).
    Both rooms 0 and 1 held 2 meetings, so we return 0. 
"""

from typing import List
import heapq
class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        count = [0] * n 
        freeRoom = list(range(n))
        heapq.heapify(freeRoom)
        used = []
        for start, end in meetings:
            while used and used[0][0] <= start:
                _, room = heapq.heappop(used)
                heapq.heappush(freeRoom, room)
            dur = end - start
            if freeRoom:
                room = heapq.heappop(freeRoom)
                begin = start
            else:
                delay, room = heapq.heappop(used)
                begin = delay
            count[room] += 1
            heapq.heappush(used, (begin + dur, room))
        maxCount = max(count)
        for i in range(n):
            if count[i] == maxCount:
                return i
            
"""
class Solution:
def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
    meetings.sort(key = lambda x : x[0])
    count = [0] * n 
    freeRoom = list(range(n))
    heapq.heapify(freeRoom)
    used = []
    for start, end in meetings:
        while used and used[0] and used[0][0] <= start:
            _, room = heapq.heappop(used)
            heapq.heappush(freeRoom, room)
        dur = end - start
        if freeRoom:
            room = heapq.heappop(freeRoom)
            begin = start
        else:
            delay, room = heapq.heappop(used)
            begin = delay
        count[room] += 1
        heapq.heappush(used, (begin + dur, room))

    maxCount = max(count)
    for i in range(n):
        if count[i] == maxCount:
            return i
"""