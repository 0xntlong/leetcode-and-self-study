/**
3559. Number of Ways to Assign Edge Weights II
    There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.
    Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.
    The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.
    You are given a 2D integer array queries. For each queries[i] = [ui, vi], determine the number of ways to assign weights to edges in the path such that the cost of the path between ui and vi is odd.
    Return an array answer, where answer[i] is the number of valid assignments for queries[i].
    Since the answer may be large, apply modulo 109 + 7 to each answer[i].
    Note: For each query, disregard all edges not in the path between node ui and vi.

    Example :

    Input: edges = [[1,2]], queries = [[1,1],[1,2]]
    Output: [0,1]
    Explanation:
    Query [1,1]: The path from Node 1 to itself consists of no edges, so the cost is 0. Thus, the number of valid assignments is 0.
    Query [1,2]: The path from Node 1 to Node 2 consists of one edge (1 → 2). Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
 */

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    static const int MOD = 1000000007;
    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n + 1);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int> depth(n + 1, 0), parent(n + 1, 0), visited(n + 1, 0);
        queue<int> q;
        q.push(1);
        visited[1] = 1;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            for (int nei : adj[node]) {
                if (!visited[nei]) {
                    visited[nei] = 1;
                    depth[nei] = depth[node] + 1;
                    parent[nei] = node;
                    q.push(nei);
                }
            }
        }
        int LOG = 1;
        while ((1 << LOG) <= n) LOG++;
        vector<vector<int>> up(LOG, vector<int>(n + 1));
        up[0] = parent;
        for (int k = 1; k < LOG; k++) {
            for (int v = 0; v <= n; v++) {
                up[k][v] = up[k - 1][up[k - 1][v]];
            }
        }

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);
            int diff = depth[u] - depth[v];
            for (int k = 0; k < LOG; k++) {
                if ((diff >> k) & 1) {
                    u = up[k][u];
                }
            }

            if (u == v) 
                return u;
            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }
            return up[0][u];

        };
        vector<int> pow2(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            pow2[i] = 1LL * pow2[i - 1] * 2 % MOD;
        }

        vector<int> ans;
        for (auto& query : queries) {
            int u = query[0];
            int v = query[1];
            int ancestor = lca(u, v);
            int dist = depth[u] + depth[v] - 2 * depth[ancestor];
            ans.push_back(dist ? pow2[dist - 1] : 0);
        }
        return ans;
    }
};