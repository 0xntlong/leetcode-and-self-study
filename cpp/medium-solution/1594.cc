/**
1594. Maximum Non Negative Product in a Matrix
    You are given a m x n matrix grid. Initially, you are located at the top-left corner (0, 0), and in each step, you can only move right or down in the matrix.
    Among all possible paths starting from the top-left corner (0, 0) and ending in the bottom-right corner (m - 1, n - 1), find the path with the maximum non-negative product. The product of a path is the product of all integers in the grid cells visited along the path.
    Return the maximum non-negative product modulo 109 + 7. If the maximum product is negative, return -1.
    Notice that the modulo is performed after getting the maximum product.
    Example :
    Input: grid = [[-1,-2,-3],[-2,-3,-3],[-3,-3,-2]]
    Output: -1
    Explanation: It is not possible to get non-negative product in the path from (0, 0) to (2, 2), so return -1.
 */



class Solution {
public:
    int maxProductPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        const int MOD = 1e9 + 7;

        vector<vector<long long>> Min(m, vector<long long>(n, LLONG_MAX));
        vector<vector<long long>> Max(m, vector<long long>(n, LLONG_MIN));

        Min[0][0] = Max[0][0] = grid[0][0];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) 
                    continue;

                long long mn = LLONG_MAX;
                long long mx = LLONG_MIN;

                if (i > 0) {
                    mn = min(mn, Min[i-1][j] * 1LL * grid[i][j]);
                    mn = min(mn, Max[i-1][j] * 1LL * grid[i][j]);
                    mx = max(mx, Min[i-1][j] * 1LL * grid[i][j]);
                    mx = max(mx, Max[i-1][j] * 1LL * grid[i][j]);
                }

                if (j > 0) {
                    mn = min(mn, Min[i][j-1] * 1LL * grid[i][j]);
                    mn = min(mn, Max[i][j-1] * 1LL * grid[i][j]);
                    mx = max(mx, Min[i][j-1] * 1LL * grid[i][j]);
                    mx = max(mx, Max[i][j-1] * 1LL * grid[i][j]);
                }

                Min[i][j] = mn;
                Max[i][j] = mx;
            }
        }

        long long res = Max[m-1][n-1];
        return res >= 0 ? res % MOD : -1;
    }
};