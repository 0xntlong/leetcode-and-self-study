/**
1970. Last Day Where You Can Still Cross
    There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.
    Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).
    You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).
    Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

    Example :
    Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
    Output: 2
    Explanation: The above image depicts how the matrix changes each day starting from day 0.
    The last day where it is possible to cross from top to bottom is on day 2.
 */


#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int dx[] = {1, -1, 0, 0};
        int dy[] = {0, 0, 1, -1};
        auto canCross = [&](int n) -> bool {
            vector<vector<char>> grid(row, vector<char>(col, 0));
            for (int i = 0; i < n; i++){
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }
            queue<pair<int, int>> q;
            for (int i = 0; i < col; i++){
                if (!grid[0][i]){
                    q.push({0, i});
                    grid[0][i] = 1;
                }
            }
            while (!q.empty()){
                auto [x, y] = q.front();
                q.pop();
                if (x == row - 1)
                    return true;
                for (int i = 0; i < 4; i++){
                    int nx = x + dx[i], ny = y + dy[i];
                    if (nx >= 0 && nx < row && ny >= 0 && ny < col && !grid[nx][ny]){
                        q.push({nx, ny});
                        grid[nx][ny] = 1;
                    }
                }
            }
            return false;
        };
        int left = 0, right = row * col;
        while (right - left > 1){
            int mid = (left + right) >> 1;
            if (canCross(mid))
                left = mid;
            else {
                right = mid;
            }
        }
        return left;
    }
};