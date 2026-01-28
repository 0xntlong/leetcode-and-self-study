/**
3651. Minimum Cost Path with Teleportations
    You are given a m x n 2D integer array grid and an integer k. You start at the top-left cell (0, 0) and your goal is to reach the bottom‐right cell (m - 1, n - 1).
    There are two types of moves available:
    Normal move: You can move right or down from your current cell (i, j), i.e. you can move to (i, j + 1) (right) or (i + 1, j) (down). The cost is the value of the destination cell.
    Teleportation: You can teleport from any cell (i, j), to any cell (x, y) such that grid[x][y] <= grid[i][j]; the cost of this move is 0. You may teleport at most k times.
    Return the minimum total cost to reach cell (m - 1, n - 1) from (0, 0).
    Example :
    Input: grid = [[1,3,3],[2,5,4],[4,3,5]], k = 2
    Output: 7
    Explanation:
    Initially we are at (0, 0) and cost is 0.
    Current Position	Move	New Position	Total Cost
    (0, 0)	Move Down	(1, 0)	0 + 2 = 2
    (1, 0)	Move Right	(1, 1)	2 + 5 = 7
    (1, 1)	Teleport to (2, 2)	(2, 2)	7 + 0 = 7
    The minimum cost to reach bottom-right cell is 7.
 */ 


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid, int k) {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        const long long INF = (long long)1e30;

        vector<pair<int,int>> cells; 
        cells.reserve(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int idx = i * n + j;
                cells.push_back({grid[i][j], idx});
            }
        }
        sort(cells.begin(), cells.end(), [](const auto& a, const auto& b){
            if (a.first != b.first) 
                return a.first > b.first;
            return a.second > b.second; 
        });

        vector<long long> dist(m * n, INF);
        dist[0] = 0;
        long long best = INF;

        for (int t = 0; t <= k; t++) {
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    int idx = i * n + j;
                    long long cur = dist[idx];
                    if (cur >= INF) 
                        continue;
                    if (j + 1 < n) {
                        int ni = idx + 1;
                        long long cost = cur + grid[i][j + 1];
                        if (cost < dist[ni]) 
                            dist[ni] = cost;
                    }
                    if (i + 1 < m) {
                        int ni = idx + n;
                        long long cost = cur + grid[i + 1][j];
                        if (cost < dist[ni]) 
                            dist[ni] = cost;
                    }
                }
            }

            best = min(best, dist[m * n - 1]);
            if (t == k) 
                break;

            vector<long long> nextDist(m * n, INF);
            long long move = INF;

            int p = 0;
            while (p < (int)cells.size()) {
                int val = cells[p].first;
                int q = p;
                long long group_min = INF;
                while (q < (int)cells.size() && cells[q].first == val) {
                    group_min = min(group_min, dist[cells[q].second]);
                    q++;
                }
                move = min(move, group_min);
                for (int t2 = p; t2 < q; t2++) {
                    int idx = cells[t2].second;
                    nextDist[idx] = move;
                }
                p = q;
            }
            dist.swap(nextDist);
        }
        return (best >= INF) ? -1 : (int)best;
    }
};