/**
1391. Check if There is a Valid Path in a Grid
    You are given an m x n grid. Each cell of grid represents a street. The street of grid[i][j] can be:
    1 which means a street connecting the left cell and the right cell.
    2 which means a street connecting the upper cell and the lower cell.
    3 which means a street connecting the left cell and the lower cell.
    4 which means a street connecting the right cell and the lower cell.
    5 which means a street connecting the left cell and the upper cell.
    6 which means a street connecting the right cell and the upper cell.
    You will initially start at the street of the upper-left cell (0, 0). A valid path in the grid is a path that starts from the upper left cell (0, 0) and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.
    Notice that you are not allowed to change any street.
    Return true if there is a valid path in the grid or false otherwise.

    Example :
    Input: grid = [[2,4,3],[6,5,2]]
    Output: true
    Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).
 */

#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        vector<unordered_set<int>> dirs = {
            {}, {0, 1}, {2, 3}, {0, 3}, {1, 3}, {0, 2}, {1, 2}
        };
        int moves[4][4] = {
            {0, -1, 0, 1}, 
            {0, 1, 1, 0},  
            {-1, 0, 2, 3}, 
            {1, 0, 3, 2} 
        };

        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            if (r == rows - 1 && c == cols - 1) 
                return true;

            for (auto& m : moves) {
                int nr = r + m[0], nc = c + m[1];
                int outDir = m[2], inDir = m[3];

                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && !visited[nr][nc]) {
                    if (dirs[grid[r][c]].count(outDir) && dirs[grid[nr][nc]].count(inDir)) {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        return false;
    }
};