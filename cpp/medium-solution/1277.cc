/*
1277. Count Square Submatrices with All Ones
    Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

    Example :
    Input: matrix =
    [
    [0,1,1,1],
    [1,1,1,1],
    [0,1,1,1]
    ]
    Output: 15
    Explanation: 
    There are 10 squares of side 1.
    There are 4 squares of side 2.
    There is  1 square of side 3.
    Total number of squares = 10 + 4 + 1 = 15.
*/

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ROW = matrix.size();
        int COL = matrix[0].size();
        vector<vector<int>> dp(ROW, vector<int> (COL, 0));
        int result = 0;
        for (int x = 0; x < ROW; x++){
            for (int y = 0; y < COL; y++){
                if (matrix[x][y] == 1){
                    dp[x][y] = 1;
                    if (x > 0 && y > 0){
                        dp[x][y] = min({
                            dp[x-1][y],
                            dp[x-1][y-1],
                            dp[x][y-1]
                        }) + 1;
                    }
                    result += dp[x][y];
                }
            }
        }
        return result;
    }
};