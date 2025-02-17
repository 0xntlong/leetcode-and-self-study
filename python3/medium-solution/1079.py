"""
1079. Letter Tile Possibilities
    You have n  tiles, where each tile has one letter tiles[i] printed on it.
    Return the number of possible non-empty sequences of letters you can make using the letters printed on those tiles.
    Example :
    Input: tiles = "AAB"
    Output: 8
    Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
"""

from collections import Counter
from functools import cache
class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        count = tuple(sorted(Counter(tiles).values()))

        @cache
        def dfs(count):
            s = 0
            for i in range(len(count)):
                if count[i] == 0:
                    continue
                new = list(count)
                new[i] -= 1
                s += 1 + dfs(tuple(new))
            return s
        return dfs(count)