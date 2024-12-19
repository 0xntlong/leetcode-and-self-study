/*
2133. Check if Every Row and Column Contains All Numbers
    An n x n matrix is valid if every row and every column contains all the integers from 1 to n (inclusive).
    Given an n x n integer matrix matrix, return true if the matrix is valid. Otherwise, return false.

    Example :
    Input: matrix = [[1,2,3],[3,1,2],[2,3,1]]
    Output: true
    Explanation: In this case, n = 3, and every row and column contains the numbers 1, 2, and 3.
    Hence, we return true.
*/


class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for (int i = 0; i < n; i++){
            set<int> row, col;
            for (int j = 0; j < n; j++){
                row.insert(matrix[i][j]);
                col.insert(matrix[j][i]);
            }
            if (row.size() != n || col.size() != n)
                return false;
        }
        return true;
    }
};