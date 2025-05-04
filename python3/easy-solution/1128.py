"""
1128. Number of Equivalent Domino Pairs
    Given a list of dominoes, dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] if and only if either (a == c and b == d), or (a == d and b == c) - that is, one domino can be rotated to be equal to another domino.
    Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length, and dominoes[i] is equivalent to dominoes[j].

    Example :
    Input: dominoes = [[1,2],[2,1],[3,4],[5,6]]
    Output: 1
"""

from collections import defaultdict
from typing import List
class Solution:
    def numEquivDominoPairs(self, dominoes: List[List[int]]) -> int:
        counter = defaultdict(int)
        for domino in dominoes:
            equi = min(domino[0], domino[1])  * 10 + max(domino[0], domino[1])
            counter[equi] += 1
        return sum(count * (count - 1) // 2 for count in counter.values())