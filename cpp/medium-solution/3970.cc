/**
3970. Shortest Path With At Most K Consecutive Identical Characters
    You are given an integer n representing the number of nodes in a directed weighted graph, numbered from 0 to n - 1. This is represented by a 2D integer array edges, where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with weight wi.
    You are also given a string labels of length n, where labels[i] is the character assigned to node i, and an integer k.
    Return the minimum total edge weight of a path from node 0 to node n - 1 such that the concatenation of the labels of the nodes along the path contains at most k consecutive identical characters. If no valid path exists, return -1.

    Example :
    Input: n = 3, edges = [[0,1,1],[1,2,1],[0,2,3]], labels = "aab", k = 1
    Output: 3
    Explanation:
    The optimal valid path from node 0 to node 2 is as follows:
    Use edges[2] = [0, 2, 3] to reach node 2 with a weight wi = 3.
    The corresponding concatenation of labels is "ab", which satisfies at most k = 1 consecutive identical characters. Thus, the answer is 3.
 */

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        struct Edge { 
            int v, w; bool same; 
        };

        vector<vector<Edge>> graph(n);

        for (const auto& e : edges) {
            int u = e[0], v = e[1], w = e[2];
            graph[u].push_back({v, w, labels[u] == labels[v]});
        }

        vector<int> done(n, k + 1);

        using State = tuple<long long, int, int>;
        priority_queue<State, vector<State>, greater<State>> heap;
        heap.emplace(0, 0, 1);

        while (!heap.empty()) {
            auto [d, u, r] = heap.top();
            heap.pop();

            if (r >= done[u]) continue;
            done[u] = r;

            if (u == n - 1) return static_cast<int>(d);

            for (const auto& e : graph[u]) {
                int nr = e.same ? r + 1 : 1;

                if (nr < done[e.v]) {
                    heap.emplace(d + e.w, e.v, nr);
                }
            }
        }

        return -1;
    }
};