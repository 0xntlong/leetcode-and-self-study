/**
498. Diagonal Traverse
    Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

    Example 1:
    Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [1,2,4,7,5,3,6,8,9]
 */

#include <vector>
using namespace std;


class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> res;
        res.reserve(m * n);
        int i = 0, j = 0, dir = 1;
        for (int cnt = 0; cnt < m * n; cnt++){
            res.push_back(mat[i][j]);
            if (dir == 1){
                if (j == n - 1){
                    i++;
                    dir = -1;
                } else if (i == 0){
                    j++;
                    dir = -1;
                } else {
                    i--;
                    j++;
                }
            } else {
                if (i == m - 1){
                    j++;
                    dir = 1;
                } else if (j == 0){
                    i++;
                    dir = 1;
                } else {
                    i++;
                    j--;
                }
            }
        }
        return res;
    }
};