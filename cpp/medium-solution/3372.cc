/*
3372. Maximize the Number of Target Nodes After Connecting Trees I
    There exist two undirected trees with n and m nodes, with distinct labels in ranges [0, n - 1] and [0, m - 1], respectively.
    You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree. You are also given an integer k.
    Node u is target to node v if the number of edges on the path from u to v is less than or equal to k. Note that a node is always target to itself.
    Return an array of n integers answer, where answer[i] is the maximum possible number of nodes target to node i of the first tree if you have to connect one node from the first tree to another node in the second tree.
    Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

    Example :
    Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]], k = 2
    Output: [9,7,9,8,8]
    Explanation:
    For i = 0, connect node 0 from the first tree to node 0 from the second tree.
    For i = 1, connect node 1 from the first tree to node 0 from the second tree.
    For i = 2, connect node 2 from the first tree to node 4 from the second tree.
    For i = 3, connect node 3 from the first tree to node 4 from the second tree.
    For i = 4, connect node 4 from the first tree to node 4 from the second tree.
 */

#include <vector>
using namespace std;
class Solution {
public:
    void build_adj(const vector<vector<int>>& edges, vector<vector<int>>& adj){
        for (const auto& edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    int DFS(int node, int parent, int maxLen, const vector<vector<int>>& adj){
        if (maxLen < 0){
            return 0;
        }
        int count = 1;
        for (int nei : adj[node]){
            if (nei != parent){
                count += DFS(nei, node, maxLen - 1, adj);
            }
        }
        return count;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;
        vector<vector<int>> adj1(n), adj2(m);
        build_adj(edges1, adj1);
        build_adj(edges2, adj2);
        int max_cnt2 = 0;
        for (int i = 0; i < m; i++){
            max_cnt2 = max(max_cnt2, DFS(i, -1, k - 1, adj2));
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++){
            int cnt1 = DFS(i, -1, k, adj1);
            res[i] = cnt1 + max_cnt2;
        }
        return res;
    }   
};