/**
3620. Network Recovery Pathways
    You are given a directed acyclic graph of n nodes numbered from 0 to n − 1. This is represented by a 2D array edges of length m, where edges[i] = [ui, vi, costi] indicates a one‑way communication from node ui to node vi with a recovery cost of costi.
    Some nodes may be offline. You are given a boolean array online where online[i] = true means node i is online. Nodes 0 and n − 1 are always online.
    A path from 0 to n − 1 is valid if:
    All intermediate nodes on the path are online.
    The total recovery cost of all edges on the path does not exceed k.
    For each valid path, define its score as the minimum edge‑cost along that path.
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
    The minimum edge‐cost along this path is min(3, 4) = 3.
    There are no other valid paths. Hence, the maximum among all valid path‐scores is 3.
 */




class Solution {
public:
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int maxWeight = 0;
        unordered_map<int, vector<pair<int, int>>> graph;

        for (auto& e : edges) {
            int fromNode = e[0];
            int toNode = e[1];
            int weight = e[2];
            graph[fromNode].push_back({toNode, weight});
            maxWeight = max(maxWeight, weight);
        }

        auto check = [&](int minWeight) {
            priority_queue<pair<long long, int>,vector<pair<long long, int>>,greater<pair<long long, int>>> heap;
            heap.push({0, 0});
            unordered_map<int, long long> bestCost;
            while (!heap.empty()) {
                auto [currentCost, currentNode] = heap.top();
                heap.pop();
                if (currentNode == online.size() - 1) {
                    return true;
                }
                if (bestCost.count(currentNode) && bestCost[currentNode] <= currentCost) {
                    continue;
                }
                bestCost[currentNode] = currentCost;
                for (auto& [nextNode, edgeWeight] : graph[currentNode]) {
                    if (currentCost + edgeWeight > k) {
                        continue;
                    }
                    if (!online[nextNode]) {
                        continue;
                    }
                    if (edgeWeight < minWeight) {
                        continue;
                    }
                    heap.push({currentCost + edgeWeight, nextNode});
                }
            }
            return false;
        };
        int left = -1;
        int right = maxWeight + 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (check(mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right >= 0 ? right : -1;
    }
};