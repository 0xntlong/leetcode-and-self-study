/**
3742. Maximum Path Score in a Grid
    You are given an m x n grid where each cell contains one of the values 0, 1, or 2. You are also given an integer k.
    You start from the top-left corner (0, 0) and want to reach the bottom-right corner (m - 1, n - 1) by moving only right or down.
    Each cell contributes a specific score and incurs an associated cost, according to their cell values:
    0: adds 0 to your score and costs 0.
    1: adds 1 to your score and costs 1.
    2: adds 2 to your score and costs 1. ​​​​​​​
    Return the maximum score achievable without exceeding a total cost of k, or -1 if no valid path exists.
    Note: If you reach the last cell but the total cost exceeds k, the path is invalid.

    Example :
    Input: grid = [[0, 1],[2, 0]], k = 1
    Output: 2
    Explanation:​​​​​​​
    The optimal path is:
    Cell	grid[i][j]	Score	Total
    Score	Cost	Total
    Cost
    (0, 0)	0	0	0	0	0
    (1, 0)	2	2	2	1	1
    (1, 1)	0	0	2	0	1
    Thus, the maximum possible score is 2.
 */

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(k + 1, -1));

        dp[0][k] = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int curr = grid[i][j];
                vector<int> combined(k + 1, -1);
                for (int rk = 0; rk <= k; rk++) {
                    combined[rk] = max(combined[rk], dp[j][rk]);
                }

                if (j > 0) {
                    for (int rk = 0; rk <= k; rk++) {
                        combined[rk] = max(combined[rk], dp[j - 1][rk]);
                    }
                }
                if (curr != 0) {
                    fill(dp[j].begin(), dp[j].end(), -1);
                    for (int rk = 1; rk <= k; rk++) {
                        if (combined[rk] != -1) {
                            dp[j][rk - 1] = combined[rk] + curr;
                        }
                    }
                } else {
                    dp[j] = combined;
                }
            }
        }
        int max_val = -1;
        for (int rk = 0; rk <= k; rk++) {
            max_val = max(max_val, dp[n - 1][rk]);
        }
        return max_val;
    }
};