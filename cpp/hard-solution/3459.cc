/**
3459. Length of Longest V-Shaped Diagonal Segment
    You are given a 2D integer matrix grid of size n x m, where each element is either 0, 1, or 2.
    A V-shaped diagonal segment is defined as:
    The segment starts with 1.
    The subsequent elements follow this infinite sequence: 2, 0, 2, 0, ....
    The segment:
    Starts along a diagonal direction (top-left to bottom-right, bottom-right to top-left, top-right to bottom-left, or bottom-left to top-right).
    Continues the sequence in the same diagonal direction.
    Makes at most one clockwise 90-degree turn to another diagonal direction while maintaining the sequence.

    Return the length of the longest V-shaped diagonal segment. If no valid segment exists, return 0.

    Example :
    Input: grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]
    Output: 5
    Explanation:
    The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: (0,2) → (1,3) → (2,4), takes a 90-degree clockwise turn at (2,4), and continues as (3,3) → (4,2).
 */


#include <vector>
#include <array>
#include <functional>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lenOfVDiagonal(vector<vector<int>>& grid) {
        const int n = (int)grid.size();
        const int m = (int)grid[0].size();
        const int di[4] = {1, 1, -1, -1};
        const int dj[4] = {1, -1, -1, 1};
        auto next_val = [&](int v) -> int{
            return (v == 2 ? 0 : 2);
        };
        vector<vector<array<array<int, 2>, 4>>> dp (
            n, vector<array<array<int, 2>, 4>>(m, array<array<int, 2>, 4>{})
        );
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                for (int d = 0; d < 4; d++){
                    for (int t = 0; t < 2; t++){
                        dp[i][j][d][t] = -1;
                    }
                }
            }
        }
        function<int(int, int, int, int)> dfs = [&](int x, int y, int turned, int dir) -> int{
            int &memo = dp[x][y][dir][turned];
            if (memo != -1)
                return memo;
                int res = 1;
                int need = next_val(grid[x][y]);
                int nx = x + di[dir], ny = y + dj[dir];
                if (0 <= nx && nx < n && 0 <= ny && ny < m && grid[nx][ny] == need){
                    res = max(res, 1 + dfs(nx, ny, turned, dir));
                }
                if (turned == 0){
                    int ndir = (dir + 1) & 3;
                    int tx = x + di[ndir], ty = y + dj[ndir];
                    if (0 <= tx && tx < n && 0 <= ty && ty < m && grid[tx][ty] == need){
                        res = max(res, 1 + dfs(tx, ty, 1, ndir));
                    }
                }
                return memo = res;
        };
        int total = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (grid[i][j] != 1) continue;
                int tm[4] = {n - i, j + 1, i + 1, m - j};
                for (int d = 0; d < 4; d++){
                    if (tm[d] > total){
                        total = max(total, dfs(i, j, 0, d));
                    }
                }
            }
        }
        return total;
    }
};