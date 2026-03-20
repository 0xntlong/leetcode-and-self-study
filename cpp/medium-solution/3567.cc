/**
3567. Minimum Absolute Difference in Sliding Submatrix
    You are given an m x n integer matrix grid and an integer k.
    For every contiguous k x k submatrix of grid, compute the minimum absolute difference between any two distinct values within that submatrix.
    Return a 2D array ans of size (m - k + 1) x (n - k + 1), where ans[i][j] is the minimum absolute difference in the submatrix whose top-left corner is (i, j) in grid.
    Note: If all elements in the submatrix have the same value, the answer will be 0.
    A submatrix (x1, y1, x2, y2) is a matrix that is formed by choosing all cells matrix[x][y] where x1 <= x <= x2 and y1 <= y <= y2.

    Example :
    Input: grid = [[1,8],[3,-2]], k = 2
    Output: [[2]]
    Explanation:
    There is only one possible k x k submatrix: [[1, 8], [3, -2]].
    Distinct values in the submatrix are [1, 8, 3, -2].
    The minimum absolute difference in the submatrix is |1 - 3| = 2. Thus, the answer is [[2]].
 */


#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<int>> res(rows - k + 1, vector<int>(cols - k + 1));

        auto computeDiff = [&](multiset<int>& window) {
            if (window.size() < 2) 
                return 0;

            int minDiff = INT_MAX;
            auto prev = window.begin();
            auto it = next(prev);

            while (it != window.end()) {
                int d = *it - *prev;
                if (d > 0) minDiff = min(minDiff, d);
                prev = it;
                it++;
            }

            return minDiff == INT_MAX ? 0 : minDiff;
        };

        for (int r = 0; r <= rows - k; r++) {
            multiset<int> window;

            for (int i = 0; i < k; i++)
                for (int j = 0; j < k; j++)
                    window.insert(grid[r + i][j]);

            res[r][0] = computeDiff(window);

            for (int c = 1; c <= cols - k; c++) {
                for (int i = 0; i < k; i++)
                    window.erase(window.find(grid[r + i][c - 1]));

                for (int i = 0; i < k; i++)
                    window.insert(grid[r + i][c + k - 1]);

                res[r][c] = computeDiff(window);
            }
        }

        return res;
    }
};