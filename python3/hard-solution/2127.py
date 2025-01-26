"""
2127. Maximum Employees to Be Invited to a Meeting
    A company is organizing a meeting and has a list of n employees, waiting to be invited. They have arranged for a large circular table, capable of seating any number of employees.
    The employees are numbered from 0 to n - 1. Each employee has a favorite person and they will attend the meeting only if they can sit next to their favorite person at the table. The favorite person of an employee is not themself.
    Given a 0-indexed integer array favorite, where favorite[i] denotes the favorite person of the ith employee, return the maximum number of employees that can be invited to the meeting.

    Example :
    Input: favorite = [2,2,1,2]
    Output: 3
"""

from collections import deque
from typing import List
class Solution:
    def maximumInvitations(self, favorite: List[int]) -> int:
        n = len(favorite)
        deg = [0] * n 
        for i in favorite:
            deg[i] += 1
        q = deque()

        for i in range(n):
            if deg[i] == 0:
                q.append(i)
        chain = [1] * n
        d = 1

        while q:
            Que = len(q)
            for _ in range(Que):
                i = q.popleft()
                j = favorite[i]
                chain[j] = max(d + 1, chain[j])
                deg[j] -= 1
                if deg[j] == 0:
                    q.append(j)
            d += 1
        maxCycle = 0
        turn = 0

        for i in range(n):
            if deg[i] == 0:
                continue
            sizeCycle = 0
            j = i
            while deg[j] != 0:
                deg[j] = 0
                sizeCycle += 1
                j = favorite[j]
            if sizeCycle > 2:
                maxCycle = max(maxCycle, sizeCycle)
            else:
                turn += chain[i] + chain[favorite[i]]
        
        return max(maxCycle, turn)