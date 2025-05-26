/*
1857. Largest Color Value in a Directed Graph
    There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
    You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.
    A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.
    Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

    Example :
    Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
    Output: 3
    Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
 */


#include <vector>
#include <string>
#include <climits>
using namespace std;
class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<int>> freq;
    vector<int> visited;
    vector<int> cycle;

    int DFS(int node, const string& colors){
        if (cycle[node])
            return INT_MAX;
        if (visited[node])
            return freq[node][colors[node] - 'a'];
        visited[node] = cycle[node] = 1;
        for (int nei : adj[node]){
            if (DFS (nei, colors) == INT_MAX)
                return INT_MAX;
            for (int i = 0; i < 26; i++){
                freq[node][i] = max(freq[node][i], freq[nei][i]);
            }
        }
        cycle[node] = 0;
        freq[node][colors[node] - 'a']++;
        return freq[node][colors[node] - 'a'];
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        adj.resize(n);
        freq.assign(n, vector<int>(26, 0));
        visited.assign(n, 0);
        cycle.assign(n, 0);
        for (const auto& edge : edges){
            adj[edge[0]].push_back(edge[1]);
        }
        int ans = 0;
        for (int i = 0; i < n; i++){
            int val = DFS(i, colors);
            if (val == INT_MAX)
                return -1;
            ans = max(ans, val);
        }
        return ans;
    }
};