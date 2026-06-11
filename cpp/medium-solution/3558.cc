/**
3558. Number of Ways to Assign Edge Weights I
    There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.
    Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.
    The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.
    Select any one node x at the maximum depth. Return the number of ways to assign edge weights in the path from node 1 to x such that its total cost is odd.
    Since the answer may be large, return it modulo 109 + 7.
    Note: Ignore all edges not in the path from node 1 to x.


    Example :

    Input: edges = [[1,2]]

    Output: 1

    Explanation:

    The path from Node 1 to Node 2 consists of one edge (1 → 2).
    Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
*/

#include <vector>
using namespace std;

class Solution {
public:
    const long long MOD = 1e9 + 7;

    long long modPow(long long a, long long b) {
        long long res = 1;
        while (b > 0) {
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }

    int dfs(int node, int prev, vector<vector<int>>& graph) {
        int dist = 0;

        for (int c : graph[node]) {
            if (c != prev) {
                dist = max(dist, dfs(c, node, graph) + 1);
            }
        }

        return dist;
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> graph(n + 1);

        for (auto& e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int d = dfs(1, 0, graph);
        return modPow(2, d - 1);
    }
};