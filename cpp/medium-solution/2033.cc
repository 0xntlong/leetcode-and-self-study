/*
2033. Minimum Operations to Make a Uni-Value Grid
    You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
    A uni-value grid is a grid where all the elements of it are equal.
    Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

    Example :
    Input: grid = [[2,4],[6,8]], x = 2
    Output: 4
    Explanation: We can make every element equal to 4 by doing the following: 
    - Add x to 2 once.
    - Subtract x from 6 once.
    - Subtract x from 8 twice.
    A total of 4 operations were used.
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
        int minOperations(vector<vector<int>>& grid, int x) {
            const int m = grid.size(), n = grid[0].size(), N = m * n;
            vector<int> val (N, 0);
            int r = grid[0][0] % x;
            int i = 0;
            for (const auto& row : grid){
                for (int num : row){
                    auto [a, b] = div(num, x);
                    if (b != r)
                        return -1;
                    val[i++] = a;
                }
            }
            sort(val.begin(), val.end());
            int cost = (N & 1) ? val[N / 2] : (val[N/2 - 1] + val[N / 2]) / 2;
            int op = 0;
            for (int num : val){
                op += abs(num - cost);
            }
            return op;
        }
    };