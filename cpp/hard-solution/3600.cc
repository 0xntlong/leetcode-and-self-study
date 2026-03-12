/**
3600. Maximize Spanning Tree Stability with Upgrades
    You are given an integer n, representing n nodes numbered from 0 to n - 1 and a list of edges, where edges[i] = [ui, vi, si, musti]:
    ui and vi indicates an undirected edge between nodes ui and vi.
    si is the strength of the edge.
    musti is an integer (0 or 1). If musti == 1, the edge must be included in the spanning tree. These edges cannot be upgraded.
    You are also given an integer k, the maximum number of upgrades you can perform. Each upgrade doubles the strength of an edge, and each eligible edge (with musti == 0) can be upgraded at most once.
    The stability of a spanning tree is defined as the minimum strength score among all edges included in it.
    Return the maximum possible stability of any valid spanning tree. If it is impossible to connect all nodes, return -1.
    Note: A spanning tree of a graph with n nodes is a subset of the edges that connects all nodes together (i.e. the graph is connected) without forming any cycles, and uses exactly n - 1 edges.

    Example :

    Input: n = 3, edges = [[0,1,2,1],[1,2,3,0]], k = 1

    Output: 2

    Explanation:

    Edge [0,1] with strength = 2 must be included in the spanning tree.
    Edge [1,2] is optional and can be upgraded from 3 to 6 using one upgrade.
    The resulting spanning tree includes these two edges with strengths 2 and 6.
    The minimum strength in the spanning tree is 2, which is the maximum possible stability.
*/


#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

#define MOD 1000000007
class Solution {
public:
    int find(int v, std::vector<int>& parent) {
        if (parent[v] == v) {
            return v;
        }
        parent[v] = find(parent[v], parent);
        return parent[v];
    }

    bool unionSets(int a, int b, std::vector<int>& parent, std::vector<int>& size) {
        a = find(a, parent);
        b = find(b, parent);
        if (a != b) {
            if (size[a] < size[b]) {
                std::swap(a, b);
            }
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
        return false;
    }

    int maxStability(int n, std::vector<std::vector<int>>& edges, int k) {
        std::vector<int> parent(n);
        std::vector<int> size(n, 1);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }

        int comp = n;
        int res = INT_MAX;
        std::vector<int> opt;

        for (int idx = 0; idx < edges.size(); ++idx) {
            auto edge = edges[idx];
            if (edge[3] == 1) {
                if (unionSets(edge[0], edge[1], parent, size)) {
                    comp--;
                    res = std::min(res, edge[2]);
                } else {
                    return -1;
                }
            }
        }

        if (comp == 1) {
            return res;
        }

        for (int idx = 0; idx < edges.size(); ++idx) {
            if (edges[idx][3] == 0) {
                opt.push_back(idx);
            }
        }

        std::sort(opt.begin(), opt.end(), [&](int a, int b) {
            return edges[a][2] > edges[b][2];
        });

        std::vector<int> stab;

        for (int idx : opt) {
            auto edge = edges[idx];
            if (unionSets(edge[0], edge[1], parent, size)) {
                comp--;
                stab.push_back(edge[2]);
                if (comp == 1) {
                    break;
                }
            }
        }

        if (comp > 1) {
            return -1;
        }

        for (int i = 1; i <= std::min((int)stab.size(), k); ++i) {
            stab[stab.size() - i] *= 2;
        }

        return std::min(res, *std::min_element(stab.begin(), stab.end()));
    }
};