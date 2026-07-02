/**
3286. Find a Safe Walk Through a Grid
    You are given an m x n binary matrix grid and an integer health.
    You start on the upper-left corner (0, 0) and would like to get to the lower-right corner (m - 1, n - 1).
    You can move up, down, left, or right from one cell to another adjacent cell as long as your health remains positive.
    Cells (i, j) with grid[i][j] = 1 are considered unsafe and reduce your health by 1.
    Return true if you can reach the final cell with a health value of 1 or more, and false otherwise.

    Example :
    Input: grid = [[0,1,0,0,0],[0,1,0,1,0],[0,0,0,1,0]], health = 1
    Output: true
    Explanation:
    The final cell can be reached safely by walking along the gray cells below.
 */


#include <vector>
#include <deque>
using namespace std;
class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int row = grid.size();
        int col = grid[0].size();
        vector<vector<int>> dist(row, vector<int>(col, -2));
        deque<pair<int, int>> q;
        q.push_back({0, 0});
        if (grid[0][0] == 1) {
            dist[0][0] = health - 1;
            if (dist[0][0] <= 0) 
                return false;
        } else {
            dist[0][0] = health;
        }
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop_front();
            if (i == row - 1 && j == col - 1)
                return true;
            vector<pair<int, int>> dirs = {
                {i - 1, j}, {i + 1, j}, {i, j - 1}, {i, j + 1}
            };
            for (auto [x, y] : dirs) {
                if (x >= 0 && x < row && y >= 0 && y < col && dist[x][y] == -2) {
                    int cost = grid[x][y] == 1 ? 1 : 0;
                    int newHealth = dist[i][j] - cost;
                    if (newHealth > 0 && newHealth > dist[x][y]) {
                        dist[x][y] = newHealth;
                        if (cost == 0)
                            q.push_front({x, y});
                        else
                            q.push_back({x, y});
                    }
                }
            }
        }
        return false;
    }
};