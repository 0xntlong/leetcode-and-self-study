/*
2290. Minimum Obstacle Removals to Reach Corner
    You are given a 0-indexed 2D integer array grid of size m x n. Each cell has one of two values:
    0 represents an empty cell,
    1 represents an obstacle that may be removed.
    You can move up, down, left, or right from and to an empty cell.
    Return the minimum number of obstacles to remove so you can move from the upper left corner (0, 0) to the lower right corner (m - 1, n - 1).

    Example :
    Input: grid = [[0,1,1],[1,1,0],[1,1,0]]
    Output: 2
    Explanation: We can remove the obstacles at (0, 1) and (0, 2) to create a path from (0, 0) to (2, 2).
    It can be shown that we need to remove at least 2 obstacles, so we return 2.
    Note that there may be other ways to remove 2 obstacles to create a path.
*/

#include <vector>
#include <deque>
using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int Rows = grid.size();
        int Cols = grid[0].size();
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        deque<pair<int, pair<int, int>>> q;
        vector<vector<bool>> visited(Rows, vector<bool>(Cols, false));
        q.push_back({0, {0, 0}});
        while (!q.empty()){
            auto [dist, pos] = q.front();
            q.pop_front();
            int row = pos.first, col = pos.second;
            if (row == Rows - 1 && col == Cols - 1)
                return dist;
            if (visited[row][col])
                continue;
            visited[row][col] = true;
            for (auto& dir : directions){
                int dx = row + dir[0];
                int dy = col + dir[1];
                if (dx >= 0 && dx < Rows && dy >= 0 && dy < Cols && !visited[dx][dy]){
                    if (grid[dx][dy] == 1){
                        q.push_back({dist + 1, {dx, dy}});
                    } else {
                        q.push_front({dist, {dx, dy}});
                    }
                }
            }
        }
        return -1;
    }
};