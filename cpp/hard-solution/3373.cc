/*
3373. Maximize the Number of Target Nodes After Connecting Trees II
    There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.
    You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
    Node u is target to node v if the number of edges on the path from u to v is even. Note that a node is always target to itself.
    Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node i of the first tree if you had to connect one node from the first tree to another node in the second tree.
    Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

    Example 1:
    Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]
    Output: [8,7,7,8,8]
    Explanation:
    For i = 0, connect node 0 from the first tree to node 0 from the second tree.
    For i = 1, connect node 1 from the first tree to node 4 from the second tree.
    For i = 2, connect node 2 from the first tree to node 7 from the second tree.
    For i = 3, connect node 3 from the first tree to node 0 from the second tree.
    For i = 4, connect node 4 from the first tree to node 4 from the second tree.
 */

#include <bits/stdc++.h>
#include <tuple>
#include <vector>
using namespace std;
class Solution {
public:
    vector<bool> find_even(const vector<vector<int>>& edges, int n){
        vector<vector<int>> graph(n);
        for (auto& e : edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<bool> evens(n, false);
        queue<tuple<int, int, bool>> q;
        q.emplace(0, -1, true);
        while (!q.empty()){
            auto [node, parent, is_even] = q.front();
            q.pop();
            evens[node] = is_even;
            for (int child : graph[node]){
                if (child != parent){
                    q.emplace(child, node, !is_even);
                }
            }
        }
        return evens;
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n1 = edges1.size() + 1;
        int n2 = edges2.size() + 1;
        vector<bool> even1 = find_even(edges1, n1);
        vector<bool> even2 = find_even(edges2, n2);
        int total1 = count(even1.begin(), even1.end(), true);
        int total2 = count(even2.begin(), even2.end(), true);
        int mx = max(total2, n2 - total2);
        vector<int> ans(n1);
        for (int i = 0; i < n1; i++){
            ans[i] = mx + (even1[i] ? total1 : n1 - total1);
        }
        return ans;

    }
};