/*
2685. Count the Number of Complete Components
    You are given an integer n. There is an undirected graph with n vertices, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting vertices ai and bi.
    Return the number of complete connected components of the graph.
    A connected component is a subgraph of a graph in which there exists a path between any two vertices, and no vertex of the subgraph shares an edge with a vertex outside of the subgraph.
    A connected component is said to be complete if there exists an edge between every pair of its vertices.

    Example :
    Input: n = 6, edges = [[0,1],[0,2],[1,2],[3,4]]
    Output: 3
    Explanation: From the picture above, one can see that all of the components of this graph are complete.
*/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
    public:
        int countCompleteComponents(int n, vector<vector<int>>& edges) {
            vector<vector<int>> X(n);
            for (auto& edge : edges){
                int u = edge[0], v = edge[1];
                X[u].push_back(v);
                X[v].push_back(u);
            }
            vector<int> visited(n, 0);
            int res = 0;
            for (int i = 0; i < n; i++){
                if (visited[i])
                    continue;
                vector<int> bfs = {i};
                visited[i] = 1;
                 for (int j = 0; j < bfs.size(); j++) {  
                    int current_node = bfs[j];  
                    for (int k : X[current_node]) {  
                        if (!visited[k]) {
                            bfs.push_back(k);
                            visited[k] = 1;
                        }
                    }
                }
                bool complete = true;
                for (int j : bfs){
                    if (X[j].size() != bfs.size() - 1){
                        complete = false;
                        break;
                    }
                }
                if (complete){
                    res++;
                }
            }
            return res;
        }
    };