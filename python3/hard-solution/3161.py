"""
3161. Block Placement Queries
    There exists an infinite number line, with its origin at 0 and extending towards the positive x-axis.
    You are given a 2D array queries, which contains two types of queries:
    For a query of type 1, queries[i] = [1, x]. Build an obstacle at distance x from the origin. It is guaranteed that there is no obstacle at distance x when the query is asked.
    For a query of type 2, queries[i] = [2, x, sz]. Check if it is possible to place a block of size sz anywhere in the range [0, x] on the line, such that the block entirely lies in the range [0, x]. A block cannot be placed if it intersects with any obstacle, but it may touch it. Note that you do not actually place the block. Queries are separate.
    Return a boolean array results, where results[i] is true if you can place the block specified in the ith query of type 2, and false otherwise.
    Example :
    Input: queries = [[1,2],[2,3,3],[2,3,1],[2,2,2]]
    Output: [false,true,true]
    Explanation:
    For query 0, place an obstacle at x = 2. A block of size at most 2 can be placed before x = 3.
"""

from sortedcontainers import SortedList
from typing import List

class SegTree:
    def __init__(self, n: int):
        self.n = 1 << n.bit_length()
        self.tree = [0] * (self.n*2)
    def update(self, index: int, val: int):
        index += self.n
        self.tree[index] = val
        while index > 1:
            index //= 2
            self.tree[index] = max(self.tree[index * 2], self.tree[index * 2 + 1])
    def query(self, index: int) -> int:
        index += self.n
        res = self.tree[index]
        while index > 1:
            if index % 2 == 1:
                res = max(res, self.tree[index - 1])
            index //= 2
        return res

class Solution:
    def getResults(self, queries: List[List[int]]) -> List[bool]:
        Sorted = SortedList()
        inter = SegTree(max(q[1] for q in queries))
        res = []
        Sorted.add(0)
        inter.update(0, 0)
        for q in queries:
            if q[0] == 1:
                idx = Sorted.bisect(q[1])
                if idx < len(Sorted):
                    nxt = Sorted[idx]
                    inter.update(nxt, nxt - q[1])
                inter.update(q[1], q[1] - Sorted[idx - 1])
                Sorted.add(q[1])
            else:
                prev = Sorted[Sorted.bisect(q[1]) - 1]
                mx = max(q[1] - prev, inter.query(prev))
                res.append(q[2] <= mx)
        return res