/**
3195. Find the Minimum Area to Cover All Ones I
    You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.
    Return the minimum possible area of the rectangle.

    Example :

    Input: grid = [[0,1,0],[1,0,1]]
    Output: 6
    Explanation:
    The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.
 */



#include <vector>
#include <climits>
using namespace std;


class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int row = grid.size(), col = grid[0].size();
        int minRow = INT_MAX, minCol = INT_MAX, maxRow = INT_MIN, maxCol = INT_MIN;
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                if (grid[i][j] == 1){
                    minRow = min(minRow, i);
                    maxRow = max(maxRow, i);
                    minCol = min(minCol, j);
                    maxCol = max(maxCol, j);
                }
            }
        }
        return (maxRow - minRow + 1) * (maxCol - minCol + 1);
    }
};