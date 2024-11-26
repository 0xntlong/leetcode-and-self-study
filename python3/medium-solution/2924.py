"""
2924. Find Champion II
    There are n teams numbered from 0 to n - 1 in a tournament; each team is also a node in a DAG.
    You are given the integer n and a 0-indexed 2D integer array edges of length m representing the DAG, where edges[i] = [ui, vi] indicates that there is a directed edge from team ui to team vi in the graph.
    A directed edge from a to b in the graph means that team a is stronger than team b and team b is weaker than team a.
    Team a will be the champion of the tournament if there is no team b that is stronger than team a.
    Return the team that will be the champion of the tournament if there is a unique champion, otherwise, return -1.
    Notes
    A cycle is a series of nodes a1, a2, ..., an, an+1 such that node a1 is the same node as node an+1, the nodes a1, a2, ..., an are distinct, and there is a directed edge from the node ai to node ai+1 for every i in the range [1, n].
    A DAG is a directed graph that does not have any cycle.

    Example :
    Input: n = 3, edges = [[0,1],[1,2]]
    Output: 0
    Explanation: Team 1 is weaker than team 0. Team 2 is weaker than team 1. So the champion is team 0.
"""

from typing import List
class Solution:
    def findChampion(self, n: int, edges: List[List[int]]) -> int:
        count = defaultdict(int)
        for u, v in edges:
            count[v] += 1
        champion, parentCount = 0, 0
        for i in range(n):
            if not count[i]:
                champion = i
                parentCount += 1
            if parentCount == 2:
                return -1
        return champion