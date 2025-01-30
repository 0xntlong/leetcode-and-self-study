"""
2493. Divide Nodes Into the Maximum Number of Groups
    You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.
    You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.
    Divide the nodes of the graph into m groups (1-indexed) such that:
    Each node in the graph belongs to exactly one group.
    For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.
    Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.

    Example :
    Input: n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
    Output: 4
    Explanation: As shown in the image we:
    - Add node 5 to the first group.
    - Add node 1 to the second group.
    - Add nodes 2 and 4 to the third group.
    - Add nodes 3 and 6 to the fourth group.
    We can see that every edge is satisfied.
    It can be shown that that if we create a fifth group and move any node from the third or fourth group to it, at least on of the edges will not be satisfied.
"""

from typing import List
from collections import deque, defaultdict

class Solution:
    def magnificentSets(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]

        for a, b in edges:
            adj[a - 1].append(b - 1)
            adj[b - 1].append(a - 1)

        parent = list(range(n))

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def union(x, y):
            X, Y = find(x), find(y)
            if X != Y:
                parent[Y] = X

        for a, b in edges:
            union(a - 1, b - 1)

        valid = [-1] * n
        Max = defaultdict(int)

        for start in range(n):
            root = find(start)
            if valid[start] != -1:
                continue

            queue = deque([start])
            valid[start] = 0
            

            while queue:
                node = queue.popleft()
                for nei in adj[node]:
                    if valid[nei] == -1:
                        valid[nei] = 1 - valid[node]
                        queue.append(nei)
                    elif valid[nei] == valid[node]:
                        return -1

            def bfs(src):
                queue = deque([src])
                visited = [-1] * n
                visited[src] = 1
                max_depth = 1

                while queue:
                    node = queue.popleft()
                    for nei in adj[node]:
                        if visited[nei] == -1:
                            visited[nei] = visited[node] + 1
                            max_depth = max(max_depth, visited[nei])
                            queue.append(nei)

                return max_depth

            max_depth = 0
            for node in range(n):
                if find(node) == root:
                    max_depth = max(max_depth, bfs(node))

            Max[root] = max_depth
        return sum(Max.values())