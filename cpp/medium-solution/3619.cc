/**
3619. Count Islands With Total Value Divisible by K
    You are given an m x n matrix grid and a positive integer k. An island is a group of positive integers (representing land) that are 4-directionally connected (horizontally or vertically).
    The total value of an island is the sum of the values of all cells in the island.
    Return the number of islands with a total value divisible by k.

    Example :
    Input: grid = [[0,2,1,0,0],[0,5,0,0,5],[0,0,1,0,0],[0,1,4,7,0],[0,2,0,0,8]], k = 5
    Output: 2
    Explanation:
    The grid contains four islands. The islands highlighted in blue have a total value that is divisible by 5, while the islands highlighted in red do not.
 */



class Solution {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int directions[5] = {1, 0, -1, 0, 1};
        int count = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) continue;

                queue<pair<int, int>> q;
                q.emplace(i, j);

                long long total = grid[i][j];
                grid[i][j] = 0;

                while (!q.empty()) {
                    auto [r, c] = q.front();
                    q.pop();

                    for (int d = 0; d < 4; ++d) {
                        int nr = r + directions[d];
                        int nc = c + directions[d + 1];

                        if (nr < 0 || nr >= m || nc < 0 || nc >= n ||
                            grid[nr][nc] == 0) {
                            continue;
                        }

                        total += grid[nr][nc];
                        grid[nr][nc] = 0;
                        q.emplace(nr, nc);
                    }
                }

                if (total % k == 0) ++count;
            }
        }

        return count;
    }
};