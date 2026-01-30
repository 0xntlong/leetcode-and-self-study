"""
2977. Minimum Cost to Convert String II
    You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English characters. You are also given two 0-indexed string arrays original and changed, and an integer array cost, where cost[i] represents the cost of converting the string original[i] to the string changed[i].
    You start with the string source. In one operation, you can pick a substring x from the string, and change it to y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y. You are allowed to do any number of operations, but any pair of operations must satisfy either of these two conditions:
    The substrings picked in the operations are source[a..b] and source[c..d] with either b < c or d < a. In other words, the indices picked in both operations are disjoint.
    The substrings picked in the operations are source[a..b] and source[c..d] with a == c and b == d. In other words, the indices picked in both operations are identical.
    Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.
    Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

    Example :

    Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
    Output: 28
    Explanation: To convert "abcd" to "acbe", do the following operations:
    - Change substring source[1..1] from "b" to "c" at a cost of 5.
    - Change substring source[2..2] from "c" to "e" at a cost of 1.
    - Change substring source[2..2] from "e" to "b" at a cost of 2.
    - Change substring source[3..3] from "d" to "e" at a cost of 20.
    The total cost incurred is 5 + 1 + 2 + 20 = 28. 
    It can be shown that this is the minimum possible cost.
"""
from typing import List 

class Solution:
    def minimumCost(self, source: str, target: str, original: List[str], changed: List[str], cost: List[int]) -> int:
        idx_map = {}
        count = 0
        for o in original:
            if o not in idx_map:
                idx_map[o] = count
                count += 1
        for c in changed:
            if c not in idx_map:
                idx_map[c] = count
                count += 1
        
        INF = float('inf')
        dist = [[INF] * count for _ in range(count)]
        for i in range(count):
            dist[i][i] = 0

        for o, c, val in zip(original, changed, cost):
            u, v = idx_map[o], idx_map[c]
            dist[u][v] = min(dist[u][v], val)

        for k in range(count):
            for i in range(count):
                if dist[i][k] == INF:
                    continue
                for j in range(count):
                    if dist[k][j] != INF:
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j])

        possible = sorted(list(set(len(o) for o in original)))
        n = len(source)

        dp = [INF] * (n + 1)
        dp[n] = 0
        for i in range(n - 1, -1, -1):
            if source[i] == target[i]:
                dp[i] = dp[i + 1]
            for p in possible:
                if i + p > n:
                    break
                sub_s = source[i : i + p]
                sub_t = target[i : i + p]
                if sub_s in idx_map and sub_t in idx_map:
                    u, v = idx_map[sub_s], idx_map[sub_t]
                    if dist[u][v] != INF:
                        if dp[i + p] != INF:
                            dp[i] = min(dp[i], dist[u][v] + dp[i + p])

        return dp[0] if dp[0] != INF else -1