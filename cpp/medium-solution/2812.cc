/**
2812. Find the Safest Path in a Grid
    You are given a 0-indexed 2D matrix grid of size n x n, where (r, c) represents:
    A cell containing a thief if grid[r][c] = 1
    An empty cell if grid[r][c] = 0
    You are initially positioned at cell (0, 0). In one move, you can move to any adjacent cell in the grid, including cells containing thieves.
    The safeness factor of a path on the grid is defined as the minimum manhattan distance from any cell in the path to any thief in the grid.
    Return the maximum safeness factor of all paths leading to cell (n - 1, n - 1).
    An adjacent cell of cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) and (r - 1, c) if it exists.
    The Manhattan distance between two cells (a, b) and (x, y) is equal to |a - x| + |b - y|, where |val| denotes the absolute value of val.
    Example :
    Input: grid = [[1,0,0],[0,0,0],[0,0,1]]
    Output: 0
    Explanation: All paths from (0, 0) to (n - 1, n - 1) go through the thieves in cells (0, 0) and (n - 1, n - 1).
 */


#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();

        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1)
            return 0;

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] == 1) {
                    dist[r][c] = 0;
                    q.push({r, c});
                }
            }
        }

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && dist[nr][nc] == INT_MAX) {
                    dist[nr][nc] = dist[r][c] + 1;
                    q.push({nr, nc});
                }
            }
        }

        vector<vector<bool>> seen(n, vector<bool>(n, false));
        priority_queue<tuple<int, int, int>> heap;

        heap.push({dist[0][0], 0, 0});

        while (!heap.empty()) {
            auto [safe, r, c] = heap.top();
            heap.pop();

            if (seen[r][c])
                continue;

            seen[r][c] = true;

            if (r == n - 1 && c == n - 1)
                return safe;

            for (auto [dr, dc] : dirs) {
                int nr = r + dr, nc = c + dc;

                if (nr >= 0 && nr < n && nc >= 0 && nc < n && !seen[nr][nc]) {
                    int newSafe = min(safe, dist[nr][nc]);
                    heap.push({newSafe, nr, nc});
                }
            }
        }

        return -1;
    }
};