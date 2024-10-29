/*
2684. Maximum Number of Moves in Grid
    You are given a 0-indexed m x n matrix grid consisting of positive integers.

    You can start at any cell in the first column of the matrix, and traverse the grid in the following way:
    From a cell (row, col), you can move to any of the cells: (row - 1, col + 1), (row, col + 1) and (row + 1, col + 1) such that the value of the cell you move to, should be strictly bigger than the value of the current cell.
    Return the maximum number of moves that you can perform.

    Example :
    Input: grid = [[2,4,3,5],[5,4,9,3],[3,4,2,11],[10,9,13,15]]
    Output: 3
    Explanation: We can start at the cell (0, 0) and make the following moves:
    - (0, 0) -> (0, 1).
    - (0, 1) -> (1, 2).
    - (1, 2) -> (2, 3).
    It can be shown that it is the maximum number of moves that can be made.
*/

#include <vector>
using namespace std;
class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        vector<int> dp(row);
        for (int y  = 1; y < col; y++){
            int prev_col = 0;
            bool find = false;
            for (int x = 0; x < row; x++){
                int cur = -1;
                int cur_col = dp[x];
                if (x - 1 >= 0 && prev_col != -1 && grid[x][y] > grid[x-1][y-1]){
                    cur = max(cur, cur_col + 1);
                }
                if (dp[x] != -1 && grid[x][y] > grid[x][y-1]){
                    cur = max(cur, dp[x] +1);
                }
                if (x + 1 < row && dp[x+1] != -1 && grid[x][y] > grid[x+1][y-1]){
                    cur = max(cur, dp[x +1] + 1);
                }
                dp[x] = cur;
                find = find || (dp[x] != -1);
                prev_col = cur_col;
            }
            if (!find) break;
            res = y;
        }
        return res;
    }
};