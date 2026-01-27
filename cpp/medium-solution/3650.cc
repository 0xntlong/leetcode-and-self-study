/**
3650. Minimum Cost Path with Edge Reversals
    You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with cost wi.
    Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its incoming edges vi → ui reverse that edge to ui → vi and immediately traverse it.
    The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.
    Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.

    Example :
    Input: n = 4, edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]
    Output: 5
    Explanation:
    Use the path 0 → 1 (cost 3).
    At node 1 reverse the original edge 3 → 1 into 1 → 3 and traverse it at cost 2 * 1 = 2.
    Total cost is 3 + 2 = 5.
 */


#include <vector>
#include <queue>
#include <climits>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>graph(n);
        for(int i = 0;i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, 2 * w});
        }
        priority_queue<pair<int, int>,vector<pair<int, int>>,greater<pair<int, int>>>pq;
        pq.push({0, 0});
        vector<int> ans(n, INT_MAX);
        ans[0] = 0;
        while(!pq.empty()){
            int weight = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it : graph[node]){
                int nd = it.first;
                int wt = it.second;
                if(wt + weight < ans[nd]){
                    ans[nd] = wt + weight;
                    pq.push({ans[nd], nd});
                }
            }
        }
        return ans[n-1] == INT_MAX ? -1 : ans[n-1];
    }
};