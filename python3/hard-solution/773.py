"""
773. Sliding Puzzle
    On an 2 x 3 board, there are five tiles labeled from 1 to 5, and an empty square represented by 0. A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
    The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
    Given the puzzle board board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.

    Example :
    Input: board = [[1,2,3],[4,0,5]]
    Output: 1
    Explanation: Swap the 0 and the 5 in one move.
"""

from collections import deque
from typing import List
class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        adj = [
            [1, 3], [0, 2 , 4], [1, 5],
            [0, 4], [1, 3, 5], [2, 4]
        ]
        shift = [15, 12, 9, 6 , 3, 0]
        target = (1 << 15) + (2 << 12) + (3 << 9) + (4 << 6) + (5 << 3) + (0 << 0)
        start = 0
        ind0 = -1
        for i in range(2):
            for j in range(3):
                index = i * 3 + j
                start += board[i][j] << shift[index]
                if board[i][j] == 0:
                    idx0 = index
        if start == target:
            return 0
        viz = set()
        que = deque([(start, idx0)])
        viz.add(start)
        moves = 0
        while que:
            for _ in range(len(que)):
                t, p0 = que.popleft()
                if t == target:
                    return moves
                for p in adj[p0]:
                    s = t
                    P = shift[p]
                    x = (s >> P) & 7
                    s += -(x << P) + (x << shift[p0])
                    if s in viz:
                        continue
                    que.append((s, p))
                    viz.add(s)
            moves += 1
        return -1