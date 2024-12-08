"""
1971. Find if Path Exists in Graph
    There is a bi-directional graph with n vertices, where each vertex is labeled from 0 to n - 1 (inclusive). The edges in the graph are represented as a 2D integer array edges, where each edges[i] = [ui, vi] denotes a bi-directional edge between vertex ui and vertex vi. Every vertex pair is connected by at most one edge, and no vertex has an edge to itself.
    You want to determine if there is a valid path that exists from vertex source to vertex destination.
    Given edges and the integers n, source, and destination, return true if there is a valid path from source to destination, or false otherwise.

    Example :
    Input: n = 3, edges = [[0,1],[1,2],[2,0]], source = 0, destination = 2
    Output: true
    Explanation: There are two paths from vertex 0 to vertex 2:
    - 0 → 1 → 2
    - 0 → 2
"""

class Solution:
    def validPath(self, n: int, edges: List[List[int]], source: int, destination: int) -> bool:
        graph = [[] for _ in range(n)]
        for edge in edges:
            graph[edge[0]].append(edge[1])
            graph[edge[1]].append(edge[0])
        def solve(graph, source, destination, visited):
            if source == destination:
                return True
            visited[source] = 1
            for nei in graph[source]:
                if visited[nei] == 0:
                    if solve(graph, nei, destination, visited):
                        return True
            return False
        visited = [0] * n
        return solve(graph, source, destination, visited)