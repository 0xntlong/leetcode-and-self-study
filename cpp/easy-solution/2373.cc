/*
2373. Largest Local Values in a Matrix
    You are given an n x n integer matrix grid.
    Generate an integer matrix maxLocal of size (n - 2) x (n - 2) such that:
    maxLocal[i][j] is equal to the largest value of the 3 x 3 matrix in grid centered around row i + 1 and column j + 1.
    In other words, we want to find the largest value in every contiguous 3 x 3 matrix in grid.
    Return the generated matrix.

    Example :
    Input: grid = [[9,9,8,1],[5,6,2,6],[8,2,6,4],[6,2,2,2]]
    Output: [[9,9],[8,6]]
    Explanation: The diagram above shows the original matrix and the generated matrix.
    Notice that each value in the generated matrix corresponds to the largest value of a contiguous 3 x 3 matrix in grid.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<vector<int>> result(n - 2, vector<int>(n - 2, 0));
        for (int i = 1; i < n - 1; i++){
            for (int j = 1; j < n - 1; j++){
                int maxVal = 0;
                for (int row = i - 1; row <= i + 1; row++){
                    for (int col = j - 1; col <= j + 1; col++){
                        maxVal = max(maxVal, grid[row][col]);
                    }
                }
                result[i - 1][j - 1] = maxVal;
            }
        }
        return result;
    }
};