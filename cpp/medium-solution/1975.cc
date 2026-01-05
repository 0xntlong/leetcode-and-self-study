/*
1975. Maximum Matrix Sum
    You are given an n x n integer matrix. You can do the following operation any number of times:
    Choose any two adjacent elements of matrix and multiply each of them by -1.
    Two elements are considered adjacent if and only if they share a border.
    Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

    Example :
    Input: matrix = [[1,-1],[-1,1]]
    Output: 4
    Explanation: We can follow the following steps to reach sum equals 4:
    - Multiply the 2 elements in the first row by -1.
    - Multiply the 2 elements in the first column by -1.
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long res = 0;
        int min_matrix = INT_MAX, neg_cnt = 0;
        for(auto& row : matrix){
            for (int r : row){
                min_matrix = min(min_matrix, abs(r));
                if (r < 0){
                    res -= r;
                    neg_cnt++;
                } else {
                    res += r;
                }
            }
        }
        return (neg_cnt & 1) ? res - 2 * min_matrix : res;


        // long long total = 0;
        // int cnt = 0;
        // int mini = INT_MAX;
        // int row = matrix.size();
        // int col = matrix[0].size();
        // for (int i = 0; i < row; i++){
        //     for (int j = 0; j < col; j++){
        //         total += abs(matrix[i][j]);
        //         if (matrix[i][j] < 0){
        //             cnt++;
        //         }
        //         mini = min(mini, abs(matrix[i][j]));
        //     }
        // }
        // if (cnt % 2)
        //     total -= 2 * mini;
        // return total;
    }
};