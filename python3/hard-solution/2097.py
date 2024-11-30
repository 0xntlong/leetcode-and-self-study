"""
2097. Valid Arrangement of Pairs
    You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti, endi]. An arrangement of pairs is valid if for every index i where 1 <= i < pairs.length, we have endi-1 == starti.
    Return any valid arrangement of pairs.
    Note: The inputs will be generated such that there exists a valid arrangement of pairs.

    Example :
    Input: pairs = [[5,1],[4,5],[11,9],[9,4]]
    Output: [[11,9],[9,4],[4,5],[5,1]]
    Explanation:
    This is a valid arrangement since endi-1 always equals starti.
    end0 = 9 == 9 = start1 
    end1 = 4 == 4 = start2
    end2 = 5 == 5 = start3
"""

from collections import defaultdict
from typing import List
class Solution:
    def validArrangement(self, pairs: List[List[int]]) -> List[List[int]]:
        graph = defaultdict(list)
        degrees = defaultdict(int)
        for start, end in pairs:
            graph[start].append(end)
            degrees[start] += 1
            degrees[end] -= 1
        start_node = pairs[0][0]
        for i in degrees:
            if degrees[i] == 1:
                start_node = i
                break
        ans = []
        def construct(node):
            while graph[node]:
                next_node = graph[node].pop()
                construct(next_node)
                ans.append((node, next_node))
        construct(start_node)
        return ans[::-1]