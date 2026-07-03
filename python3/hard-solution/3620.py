"""
3620. Network Recovery Pathways
    You are given a directed acyclic graph of n nodes numbered from 0 to n - 1. This is represented by a 2D array edges of length m, where edges[i] = [ui, vi, costi] indicates a one-way communication from node ui to node vi with a recovery cost of costi.
    Some nodes may be offline. You are given a boolean array online where online[i] = true means node i is online. Nodes 0 and n - 1 are always online.
    A path from 0 to n - 1 is valid if:
    All intermediate nodes on the path are online.
    The total recovery cost of all edges on the path does not exceed k.
    For each valid path, define its score as the minimum edge-cost along that path.
    Return the maximum path score (i.e., the largest minimum-edge cost) among all valid paths. If no valid path exists, return -1.
    
    Example 1:
    Input: edges = [[0,1,5],[1,3,10],[0,2,3],[2,3,4]], online = [true,true,true,true], k = 10
    Output: 3
    Explanation:
    The graph has two possible routes from node 0 to node 3:
    Path 0 → 1 → 3
    Total cost = 5 + 10 = 15, which exceeds k (15 > 10), so this path is invalid.
    Path 0 → 2 → 3
    Total cost = 3 + 4 = 7 <= k, so this path is valid.
    The minimum edge-cost along this path is min(3, 4) = 3.
    There are no other valid paths. Hence, the maximum among all valid path-scores is 3.
 """
from collections import defaultdict
from typing import List
import heapq


class Solution:
    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        max_weight = 0
        graph = defaultdict(list)
        for from_node, to_node, weight in edges:
            graph[from_node].append((to_node, weight))
            max_weight = max(max_weight, weight)

        def check(min_weight):
            heap = []
            heapq.heappush(heap, (0, 0))
            best_cost = defaultdict(int)
            while heap:
                current_cost, current_node = heapq.heappop(heap)
                if current_node == len(online) - 1:
                    return True
                if current_node in best_cost and best_cost[current_node] <= current_cost:
                    continue
                best_cost[current_node] = current_cost
                for next_node, edge_weight in graph[current_node]:
                    if current_cost + edge_weight > k:
                        continue
                    if not online[next_node]:
                        continue
                    if edge_weight < min_weight:
                        continue

                    heapq.heappush(heap,(current_cost + edge_weight, next_node))
            return False
        left = -1
        right = max_weight + 1
        while left <= right:
            mid = (left + right) // 2
            if check(mid):
                left = mid + 1
            else:
                right = mid - 1
        return right if right >= 0 else -1