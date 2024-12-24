/*
3203. Find the Minimum Diameter After Merging Two Trees
    There exist two undirected trees with n and m nodes, numbered from 0 to n - 1 and from 0 to m - 1, respectively. You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
    You must connect one node from the first tree with another node from the second tree with an edge.
    Return the minimum possible diameter of the resulting tree.
    The diameter of a tree is the length of the longest path between any two nodes in the tree.

    Example :
    Input: edges1 = [[0,1],[0,2],[0,3]], edges2 = [[0,1]]
    Output: 3
    Explanation:
    We can obtain a tree of diameter 3 by connecting node 0 from the first tree with any node from the second tree.
*/

#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        auto diameter = [](vector<vector<int>>& edges){
            int n = edges.size() + 1;
            vector<int> degree(n, 0);
            vector<vector<int>> adj(n);
            for (const auto& edge : edges){
                int v = edge[0], w = edge[1];
                adj[v].push_back(w);
                adj[w].push_back(v);
                degree[v]++;
                degree[w]++;
            }
            deque<int> q;
            for (int i = 0; i < n; i++){
                if (degree[i] == 1){
                    q.push_back(i);
                }
            }
            int level = 0, left = n;
            while (left > 2){
                int size_q = q.size();
                left -= size_q;
                for (int i = 0; i < size_q; i++){
                    int v = q.front();
                    q.pop_front();
                    for( int w : adj[v]){
                        degree[w]--;
                        if (degree[w] == 1){
                            q.push_back(w);
                        }
                    }
                }
                level++;
            }
            return left == 2 ? 2 * level + 1 : 2 * level;
        };
        int d1 = diameter(edges1);
        int d2 = diameter(edges2);
        return max({d1, d2, ((d1 + 1) / 2) + ((d2 + 1) / 2) + 1});
    }
};