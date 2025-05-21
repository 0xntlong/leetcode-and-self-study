/**
73. Set Matrix Zeroes
    Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
    You must do it in place.

    Example :
    Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
    Output: [[1,0,1],[0,0,0],[1,0,1]]
 */


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bitset<200> col0 = 0, row0 = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                if (matrix[i][j] == 0){
                    row0.set(i);
                    col0.set(j);
                }
            }
        }
        for (int i = 0; i < n; i++){
            if (row0.test(i)){
                for (int j = 0; j < m; j++){
                    matrix[i][j] = 0;
                }
            }
        }
        for (int j = 0; j < m; j++){
            if (col0.test(j)){
                for (int i = 0; i < n; i++){
                    matrix[i][j] = 0;
                }
            }
        }
    }
};