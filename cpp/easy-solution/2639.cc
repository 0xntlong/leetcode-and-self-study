/*
2639. Find the Width of the Columns in a Grid
    You are given a 0-indexed m x n integer matrix grid. The width of a column is the maximum length of its integers.
    For example, if grid = [[-10], [3], [12]], the width of the only column is 3 since -10 is of length 3.
    Return an integer array ans of size n where ans[i] is the width of the ith column.
    The length of an integer x with len digits is equal to len if x is non-negative, and len + 1 otherwise.

    Example :
    Input: grid = [[1],[22],[333]]
    Output: [3]
    Explanation: In the 0th column, 333 is of length 3.
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int digit(int n){
            if (n == 0)
                return 1;
            int ans = 0;
            if (n < 0)
                ans++;
            n = abs(n);
            while (n){
                ans++;
                n /= 10;
            }
            return ans;
    
        }
        vector<int> findColumnWidth(vector<vector<int>>& grid) {
            int m = grid.size(), n = grid[0].size();
            vector<int> ans(n);
            for(int i = 0; i < m; i++){
                for (int j = 0; j < n; j++){
                    ans[j] = max(ans[j], digit(grid[i][j]));
                }
            }
            return ans;
        }
    };