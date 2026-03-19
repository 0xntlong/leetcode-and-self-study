/**
3212. Count Submatrices With Equal Frequency of X and Y
    Given a 2D character matrix grid, where grid[i][j] is either 'X', 'Y', or '.', return the number of submatrices that contain:
    grid[0][0]
    an equal frequency of 'X' and 'Y'.
    at least one 'X'.

    Example :

    Input: grid = [["X","Y","."],["Y",".","."]]

    Output: 3
 */
#include <vector>
using namespace std;

class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> ox(n, 0);
        vector<int> oy(n, 0);

        int res = 0;

        for (int i = 0; i < m; i++) {
            int rowX = 0, rowY = 0;

            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 'X')
                    rowX++;
                else if (grid[i][j] == 'Y')
                    rowY++;

                ox[j] += rowX;
                oy[j] += rowY;

                if (ox[j] == oy[j] && ox[j] > 0)
                    res++;
            }
        }

        return res;

    }
};