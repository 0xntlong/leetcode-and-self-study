"""
1462. Course Schedule IV
    There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you want to take course bi.
    For example, the pair [0, 1] indicates that you have to take course 0 before you can take course 1.
    Prerequisites can also be indirect. If course a is a prerequisite of course b, and course b is a prerequisite of course c, then course a is a prerequisite of course c.
    You are also given an array queries where queries[j] = [uj, vj]. For the jth query, you should answer whether course uj is a prerequisite of course vj or not.
    Return a boolean array answer, where answer[j] is the answer to the jth query.

    Example :
    Input: numCourses = 2, prerequisites = [[1,0]], queries = [[0,1],[1,0]]
    Output: [false,true]
    Explanation: The pair [1, 0] indicates that you have to take course 1 before you can take course 0.
    Course 0 is not a prerequisite of course 1, but the opposite is true.
"""

from collections import deque
from typing import List

class Solution:
    def checkIfPrerequisite(self, numCourses: int, prerequisites: List[List[int]], queries: List[List[int]]) -> List[bool]:
        path = [0] * numCourses
        adj = [[] for _ in range(numCourses)]
        deg = [0] * numCourses
        for a, b in prerequisites:
            adj[a].append(b)
            path[b] |= ( 1 << a)
            deg[b] += 1
            
        queue = deque()

        for i in range(numCourses):
            if deg[i] == 0:
                queue.append(i)

        while queue:
            i = queue.popleft()
            for j in adj[i]:
                path[j] |= path[i]
                deg[j] -= 1
                if deg[j] == 0:
                    queue.append(j)

        ans = [False] * len(queries)

        for i, (u, v) in enumerate(queries):
            ans[i] = (path[v] >> u) & 1 == 1

        return ans 