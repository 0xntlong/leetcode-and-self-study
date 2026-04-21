"""
1722. Minimize Hamming Distance After Swap Operations
    You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.
    The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).
    Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.

    Example :
    Input: source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
    Output: 1
    Explanation: source can be transformed the following way:
    - Swap indices 0 and 1: source = [2,1,3,4]
    - Swap indices 2 and 3: source = [2,1,4,3]
    The Hamming distance of source and target is 1 as they differ in 1 position: index 3.
"""

from collections import defaultdict
from typing import List

class Solution:
    def minimumHammingDistance(self, source: List[int], target: List[int], allowedSwaps: List[List[int]]) -> int:
        n = len(source)
        parent = list(range(n))
        rank = [0] * n

        def find(x):
            if parent[x] != x:
                parent[x] = find(parent[x])
            return parent[x]

        def uni(a, b):
            fa, fb = find(a), find(b)
            if fa == fb:
                return

            if rank[fa] < rank[fb]:
                fa, fb = fb, fa

            parent[fb] = fa
            if rank[fa] == rank[fb]:
                rank[fa] += 1

        for a, b in allowedSwaps:
            uni(a, b)

        groups = defaultdict(list)
        for i in range(n):
            groups[find(i)].append(i)

        ans = 0

        for idxs in groups.values():
            freq = {}

            for i in idxs:
                freq[source[i]] = freq.get(source[i], 0) + 1

            for i in idxs:
                if freq.get(target[i], 0) > 0:
                    freq[target[i]] -= 1
                else:
                    ans += 1

        return ans