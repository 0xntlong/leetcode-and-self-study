/*
827. Making A Large Island
    You are given an n x n binary matrix grid. You are allowed to change at most one 0 to be 1.
    Return the size of the largest island in grid after applying this operation.
    An island is a 4-directionally connected group of 1s.

    Example :
    Input: grid = [[1,0],[0,1]]
    Output: 3
    Explanation: Change one 0 to 1 and connect two 1s, then we get an island with area = 3.

*/

#include <vector>
#include <functional>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int islandId = 2;
        unordered_map<int, int> sz;
        function<int(int, int, int)> DFS = [&](int r, int c, int id){
            grid[r][c] = id;
            int size = 1;
            vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
            for (auto [dr, dc] : dir){
                int nr = r + dr, nc = c + dc;
                if (nr >= 0 && nr < n && nc >= 0 && nc < n && grid[nr][nc] == 1){
                    size += DFS(nr, nc, id);
                }
            }
            return size;
        };
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 1){
                    sz[islandId] = DFS(i, j, islandId);
                    islandId++;
                }
            }
        }
        if (sz.empty())
            return 1;
        int res = 0;
        for (const auto& [id, size] : sz) {
            res = max(res, size);
        }
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 0){
                    unordered_set<int> unique_island;
                    int p = 1;
                    vector<pair<int, int>> dir = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
                    for (auto [dr, dc] : dir) {
                        int ni = i + dr, nj = j + dc;
                        if (ni >= 0 && ni < n && nj >= 0 && nj < n && grid[ni][nj] > 1){
                            int t = grid[ni][nj];
                            if (unique_island.find(t) == unique_island.end()){
                                p += sz[t];
                                unique_island.insert(t);
                            }
                        }
                    }
                    res = max(res, p);
                }
            }
        }
        return res;
    }
};