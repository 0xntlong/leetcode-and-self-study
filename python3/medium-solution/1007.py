"""
1007. Minimum Domino Rotations For Equal Row
    In a row of dominoes, tops[i] and bottoms[i] represent the top and bottom halves of the ith domino. (A domino is a tile with two numbers from 1 to 6 - one on each half of the tile.)
    We may rotate the ith domino, so that tops[i] and bottoms[i] swap values.
    Return the minimum number of rotations so that all the values in tops are the same, or all the values in bottoms are the same.
    If it cannot be done, return -1.

    Example :
    Input: tops = [2,1,2,4,2,2], bottoms = [5,2,6,2,3,2]
    Output: 2
    Explanation: 
    The first figure represents the dominoes as given by tops and bottoms: before we do any rotations.
    If we rotate the second and fourth dominoes, we can make every value in the top row equal to 2, as indicated by the second figure.
"""

from typing import List

class Solution:
    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        n = len(tops)
        m = len(bottoms)
        if n != m:
            return -1
        TOPS = [0] * 7
        BOTTOMS = [0] * 7
        SAME = [0] * 7
        for i in range(n):
            TOPS[tops[i]] += 1
            BOTTOMS[bottoms[i]] += 1
            SAME[tops[i]] += (tops[i] == bottoms[i])
        res = float('inf')
        for j in range(1, 7):
            if TOPS[j] + BOTTOMS[j] - SAME[j] == n:
                res = min(res, min(n - TOPS[j], n - BOTTOMS[j]))
        
        return res if res != float('inf') else -1