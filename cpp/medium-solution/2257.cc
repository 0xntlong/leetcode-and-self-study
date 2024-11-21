/*
2257. Count Unguarded Cells in the Grid
    You are given two integers m and n representing a 0-indexed m x n grid. You are also given two 2D integer arrays guards and walls where guards[i] = [rowi, coli] and walls[j] = [rowj, colj] represent the positions of the ith guard and jth wall respectively.
    A guard can see every cell in the four cardinal directions (north, east, south, or west) starting from their position unless obstructed by a wall or another guard. A cell is guarded if there is at least one guard that can see it.
    Return the number of unoccupied cells that are not guarded.

    Example :
    Input: m = 4, n = 6, guards = [[0,0],[1,1],[2,3]], walls = [[0,1],[2,2],[1,4]]
    Output: 7
    Explanation: The guarded and unguarded cells are shown in red and green respectively in the above diagram.
    There are a total of 7 unguarded cells, so we return 7.

*/

#include <vector>
using namespace std;
class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (auto& w : walls){
            grid[w[0]][w[1]] = 2;
        }
        for (auto& g : guards){
            grid[g[0]][g[1]] = 2;
        }
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto& g : guards){
            for (auto& dir : directions){
                int x = g[0], y = g[1];
                while (true){
                    x += dir.first;
                    y += dir.second;
                    if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] == 2){
                        break;
                    }
                    if (grid[x][y] == 0){
                        grid[x][y] = 1;
                    }
                }
            }
        }
        int count = 0;
        for (int r = 0; r < m; r++){
            for (int c = 0; c < n; c++){
                if (grid[r][c] == 0){
                    count++;
                }
            }
        }
        return count;
    }
};