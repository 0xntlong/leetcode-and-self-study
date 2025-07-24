/**
2322. Minimum Score After Removals on a Tree
    There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
    You are given a 0-indexed integer array nums of length n where nums[i] represents the value of the ith node. You are also given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
    Remove two distinct edges of the tree to form three connected components. For a pair of removed edges, the following steps are defined:
    Get the XOR of all the values of the nodes for each of the three components respectively.
    The difference between the largest XOR value and the smallest XOR value is the score of the pair.
    For example, say the three components have the node values: [4,5,7], [1,9], and [3,3,3]. The three XOR values are 4 ^ 5 ^ 7 = 6, 1 ^ 9 = 8, and 3 ^ 3 ^ 3 = 3. The largest XOR value is 8 and the smallest XOR value is 3. The score is then 8 - 3 = 5.
    Return the minimum score of any possible pair of edge removals on the given tree.

    Example :
    Input: nums = [1,5,5,4,11], edges = [[0,1],[1,2],[1,3],[3,4]]
    Output: 9
    Explanation: The diagram above shows a way to make a pair of removals.
    - The 1st component has nodes [1,3,4] with values [5,4,11]. Its XOR value is 5 ^ 4 ^ 11 = 10.
    - The 2nd component has node [0] with value [1]. Its XOR value is 1 = 1.
    - The 3rd component has node [2] with value [5]. Its XOR value is 5 = 5.
    The score is the difference between the largest and smallest XOR value which is 10 - 1 = 9.
    It can be shown that no other pair of removals will obtain a smaller score than 9.
*/



#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int time = 0;
    int DFS(int u, int parent, const vector<vector<int>>&graph, const vector<int>& nums,
            vector<int>& xorSubTree, vector<int>& inTime, vector<int>& outTime){
        int xorVal = nums[u];
        inTime[u] = time++;
        for (int v : graph[u]){
            if (v != parent){
                xorVal ^= DFS(v, u, graph, nums, xorSubTree, inTime, outTime);
            }
        }
        outTime[u] = time;
        xorSubTree[u] = xorVal;
        return xorVal;
    }
    bool find(int u, int v, const vector<int>& inTime, const vector<int>& outTime){
        return inTime[u] <= inTime[v] && outTime[v] <= outTime[u];
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> graph(n);
        for (const auto& edge : edges){
            int u = edge[0], v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> xorSubTree(n), inTime(n), outTime(n);
        int totalXor = DFS(0, -1, graph, nums, xorSubTree, inTime, outTime);

        vector<int> subTreeRoots;
        for (const auto& edge : edges){
            int u  = edge[0], v = edge[1];
            subTreeRoots.push_back(inTime[u] > inTime[v] ? u : v);
        }
        int minScore = INT_MAX;
        int m = subTreeRoots.size();
        for (int i = 0; i < m; i++){
            for (int j = i + 1; j < m; j++){
                int u = subTreeRoots[i];
                int v = subTreeRoots[j];
                int a, b, c;
                if (find(u, v, inTime, outTime)){
                    a = xorSubTree[v];
                    b = xorSubTree[u] ^ xorSubTree[v];
                    c = totalXor ^ xorSubTree[u];
                } else if (find(v, u, inTime, outTime)){
                    a = xorSubTree[u];
                    b = xorSubTree[v] ^ xorSubTree[u];
                    c = totalXor ^ xorSubTree[v];
                } else {
                    a = xorSubTree[u];
                    b = xorSubTree[v];
                    c = totalXor ^ xorSubTree[u] ^ xorSubTree[v];
                }
                int score = max({a, b, c}) - min({a, b, c});
                minScore = min(minScore, score);
            }
        }
        return minScore;
    }
};