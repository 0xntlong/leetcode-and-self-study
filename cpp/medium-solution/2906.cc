/**
2906. Construct Product Matrix
    Given a 0-indexed 2D integer matrix grid of size n * m, we define a 0-indexed 2D matrix p of size n * m as the product matrix of grid if the following condition is met:
    Each element p[i][j] is calculated as the product of all elements in grid except for the element grid[i][j]. This product is then taken modulo 12345.
    Return the product matrix of grid.

    Example :
    Input: grid = [[1,2],[3,4]]
    Output: [[24,12],[8,6]]
    Explanation: p[0][0] = grid[0][1] * grid[1][0] * grid[1][1] = 2 * 3 * 4 = 24
    p[0][1] = grid[0][0] * grid[1][0] * grid[1][1] = 1 * 3 * 4 = 12
    p[1][0] = grid[0][0] * grid[0][1] * grid[1][1] = 1 * 2 * 4 = 8
    p[1][1] = grid[0][0] * grid[0][1] * grid[1][0] = 1 * 2 * 3 = 6
    So the answer is [[24,12],[8,6]].
 */


#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int MOD = 12345;
        
        vector<vector<int>> dp(n, vector<int>(m, 0));

        long long total = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                dp[i][j] = total;
                total = (total * grid[i][j]) % MOD;
            }
        }

        total = 1;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dp[i][j] = (dp[i][j] * total) % MOD;
                total = (total * grid[i][j]) % MOD;
            }
        }
        
        return dp;
    }
};