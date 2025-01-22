/*
1765. Map of Highest Peak
    You are given an integer matrix isWater of size m x n that represents a map of land and water cells.
    If isWater[i][j] == 0, cell (i, j) is a land cell.
    If isWater[i][j] == 1, cell (i, j) is a water cell.
    You must assign each cell a height in a way that follows these rules:
    The height of each cell must be non-negative.
    If the cell is a water cell, its height must be 0.
    Any two adjacent cells must have an absolute height difference of at most 1. A cell is adjacent to another cell if the former is directly north, east, south, or west of the latter (i.e., their sides are touching).
    Find an assignment of heights such that the maximum height in the matrix is maximized.

    Return an integer matrix height of size m x n where height[i][j] is cell (i, j)'s height. If there are multiple solutions, return any of them.

    Example :
    Input: isWater = [[0,1],[0,0]]
    Output: [[1,0],[2,1]]
    Explanation: The image shows the assigned heights of each cell.
    The blue cell is the water cell, and the green cells are the land cells.
*/


#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> oX = {1, -1, 0, 0};
    vector<int> oY = {0, 0, 1, -1};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int row = isWater.size();
        int col = isWater[0].size();
        vector<vector<int>> matrix (row, vector<int>(col, -1));
        queue<pair<int, int>> q;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (isWater[i][j] == 1){
                    matrix[i][j] = 0;
                    q.push({i, j});
                }
            }
        }
        while (!q.empty()){
            auto[x, y] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++){
                int X = oX[i] + x, Y = oY[i] + y;
                if (X >= 0 && X < row &&
                    Y >= 0 && Y < col &&
                    matrix[X][Y] == -1){
                        matrix[X][Y] = matrix[x][y] + 1;
                        q.push({X, Y});
                }
            }
        }
        return matrix;
    }
};