/*
2493. Divide Nodes Into the Maximum Number of Groups
    You are given a positive integer n representing the number of nodes in an undirected graph. The nodes are labeled from 1 to n.
    You are also given a 2D integer array edges, where edges[i] = [ai, bi] indicates that there is a bidirectional edge between nodes ai and bi. Notice that the given graph may be disconnected.
    Divide the nodes of the graph into m groups (1-indexed) such that:
    Each node in the graph belongs to exactly one group.
    For every pair of nodes in the graph that are connected by an edge [ai, bi], if ai belongs to the group with index x, and bi belongs to the group with index y, then |y - x| = 1.
    Return the maximum number of groups (i.e., maximum m) into which you can divide the nodes. Return -1 if it is impossible to group the nodes with the given conditions.

    Example :
    Input: n = 6, edges = [[1,2],[1,4],[1,5],[2,6],[2,3],[4,6]]
    Output: 4
    Explanation: As shown in the image we:
    - Add node 5 to the first group.
    - Add node 1 to the second group.
    - Add nodes 2 and 4 to the third group.
    - Add nodes 3 and 6 to the fourth group.
    We can see that every edge is satisfied.
    It can be shown that that if we create a fifth group and move any node from the third or fourth group to it, at least on of the edges will not be satisfied.
*/


#include <vector>
#include <queue>
#include <functional>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> parent(n);

        for (auto& edge : edges){
            adj[edge[0] - 1].push_back(edge[1] - 1);
            adj[edge[1] - 1].push_back(edge[0] - 1);
        }
        for (int i = 0; i < n; i++){
            parent[i] = i;
        }
        function<int(int)> find = [&](int x){
            if (parent[x] != x){
                parent[x] = find(parent[x]);
            }
            return parent[x];
        };
        auto unionSet = [&](int x, int y){
            int rootX = find(x), rootY = find(y);
            if (rootX != rootY){
                parent[rootY] = rootX;
            }
        };
        for (auto& edge : edges){
            unionSet(edge[0] - 1, edge[1] - 1);
        }
        vector<int> valid(n, -1);
        unordered_map<int, int> maxDepthComponent;
        
        for (int start = 0; start < n; start++){
            int root = find(start);
            if (valid[start] != -1)
                continue;
            queue<int> q;
            q.push(start);
            valid[start] = 0;
            bool isBipartite = true;
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for (int nei : adj[node]){
                    if (valid[nei] == -1){
                        valid[nei] = 1 - valid[node];
                        q.push(nei);
                    } else if (valid[nei] == valid[node]){
                        return -1;
                    }
                }
            }
            auto bfs = [&](int src){
                queue<int> q;
                vector<int> visited(n, -1);
                q.push(src);
                visited[src] = 1;
                int maxDepth = 1;
                while (!q.empty()){
                    int node = q.front();
                    q.pop();
                    for (int nei : adj[node]){
                        if (visited[nei] == -1){
                            visited[nei] = visited[node] + 1;
                            maxDepth = max(maxDepth, visited[nei]);
                            q.push(nei);
                        }
                    }
                }
                return maxDepth;
            };
            int maxDepth = 0; 
            for (int node = 0; node < n; node++){
                if (find(node) == root){
                    maxDepth = max(maxDepth, bfs(node));
                }
            }
            maxDepthComponent[root] = maxDepth;
        }
        int total = 0;
        for (auto& [_,depth] : maxDepthComponent){
            total += depth;
        }
        return total;
    }
};