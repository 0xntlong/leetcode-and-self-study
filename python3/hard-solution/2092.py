"""
2092. Find All People With Secret
    You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.
    Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.
    The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.
    Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.
    Example :
    Input: n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
    Output: [0,1,2,3,5]
    Explanation:
    At time 0, person 0 shares the secret with person 1.
    At time 5, person 1 shares the secret with person 2.
    At time 8, person 2 shares the secret with person 3.
    At time 10, person 1 shares the secret with person 5.
    Thus, people 0, 1, 2, 3, and 5 know the secret after all the meetings.
"""


from typing import List
import heapq    
class Solution:
    def findAllPeople(self, n: int, meetings: List[List[int]], firstPerson: int) -> List[int]:
        adj = [[] for _ in range(n)]

        for meet in meetings:
            x, y, time = meet
            adj[x].append((time, y))
            adj[y].append((time, x))

        know = [float('inf')] * n
        people = []
        pq = []
        heapq.heappush(pq, (0, 0))
        heapq.heappush(pq, (0, firstPerson))
        while pq:
            time, person = heapq.heappop(pq)
            if know[person] != float('inf'):
                continue
            people.append(person)
            know[person] = time
            for t, neighbor in adj[person]:
                if know[neighbor] != float('inf') or t < time:
                    continue
                heapq.heappush(pq, (t, neighbor))
        return people