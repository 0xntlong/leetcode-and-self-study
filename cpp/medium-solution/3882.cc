/**
3882. Minimum XOR Path in a Grid
    You are given a 2D integer array grid of size m * n.
    You start at the top-left cell (0, 0) and want to reach the bottom-right cell (m - 1, n - 1).
    At each step, you may move either right or down.
    The cost of a path is defined as the bitwise XOR of all the values in the cells along that path, including the start and end cells.
    Return the minimum possible XOR value among all valid paths from (0, 0) to (m - 1, n - 1).

    Example :
    Input: grid = [[1,2],[3,4]]
    Output: 6
    Explanation:
    There are two valid paths:
    (0, 0) → (0, 1) → (1, 1) with XOR: 1 XOR 2 XOR 4 = 7
    (0, 0) → (1, 0) → (1, 1) with XOR: 1 XOR 3 XOR 4 = 6
    The minimum XOR value among all valid paths is 6.
 */



class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        constexpr int MAX_XOR = 1024;

        vector<bitset<MAX_XOR>> dp(n);
        dp[0].set(grid[0][0]);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                bitset<MAX_XOR> reachable = dp[j];

                if (j > 0) {
                    reachable |= dp[j - 1];
                }

                bitset<MAX_XOR> next;
                int value = grid[i][j];

                for (int k = 0; k < MAX_XOR; k++) {
                    if (reachable[k]) {
                        next.set(k ^ value);
                    }
                }

                dp[j] = next;
            }
        }

        for (int k = 0; k < MAX_XOR; k++) {
            if (dp[n - 1][k]) {
                return k;
            }
        }

        return -1;
    }
};