/**
3070. Count Submatrices with Top-Left Element and Sum Less Than k
    You are given a 0-indexed integer matrix grid and an integer k.re4ắ32
    Return the number of submatrices that contain the top-left element of the grid, and have a sum less than or equal to k.
    Example :
    Input: grid = [[7,6,3],[6,6,1]], k = 18
    Output: 4
    Explanation: There are only 4 submatrices, shown in the image above, that contain the top-left element of grid, and have a sum less than or equal to 18.

 */


#include <vector>
using namespace std;

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();

        vector<long long> cols(c, 0);
        int res = 0;

        for (int i = 0; i < r; i++) {
            long long row_sum = 0;
            for (int j = 0; j < c; j++) {
                cols[j] += grid[i][j];
                row_sum += cols[j];
                if (row_sum <= k)
                    res++;
            }
        }

        return res;
    }
};