/*
2658. Maximum Number of Fish in a Grid
    You are given a 0-indexed 2D matrix grid of size m x n, where (r, c) represents:

    A land cell if grid[r][c] = 0, or
    A water cell containing grid[r][c] fish, if grid[r][c] > 0.
    A fisher can start at any water cell (r, c) and can do the following operations any number of times:
    Catch all the fish at cell (r, c), or
    Move to any adjacent water cell.
    Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally, or 0 if no water cell exists.
    An adjacent cell of the cell (r, c), is one of the cells (r, c + 1), (r, c - 1), (r + 1, c) or (r - 1, c) if it exists.

    Example :
    Input: grid = [[0,2,1,0],[4,0,0,3],[1,0,0,4],[0,3,2,0]]
    Output: 7
    Explanation: The fisher can start at cell (1,3) and collect 3 fish, then move to cell (2,3) and collect 4 fish.

*/


#include <vector>
using namespace std;
class Solution {
public:
    const int d[5] = {0, 1, 0, -1, 0};
    int r, c;
    int DFS(int i, int j, vector<vector<int>>& grid){
        int fish = grid[i][j];
        grid[i][j] = 0;
        for (int a = 0; a < 4; a++){
            int row = i + d[a];
            int col = j + d[a + 1];
            if (row < 0 || row >= r || col < 0 || col >= c || grid[row][col] == 0){
                continue;
            }
            fish += DFS(row, col, grid);
        }
        return fish;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int ans = 0;
        for (int i = 0; i < r; i++){
            for (int j = 0; j < c; j++){
                if (grid[i][j] > 0){
                    ans = max(ans, DFS(i, j, grid));
                }
            }
        }
        return ans;
    }
};