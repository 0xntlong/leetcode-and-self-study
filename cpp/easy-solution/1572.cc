/*
1572. Matrix Diagonal Sum
    Given a square matrix mat, return the sum of the matrix diagonals.
    Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.
    
    Example 1:
    Input: mat = [[1,2,3],
                 [4,5,6],
                 [7,8,9]]
    Output: 25
    Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
    Notice that element mat[1][1] = 5 is counted only once.
    
    Example 2:
    Input: mat = [[1,1,1,1],
                 [1,1,1,1],
                 [1,1,1,1],
                 [1,1,1,1]]
    Output: 8
*/

#include <vector>
using namespace std;
class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        for (int i = 0; i < mat.size(); i++){
            sum += mat[i][i];
        }
        for (int i = mat.size() - 1; i > -1; i--){
            sum += mat[mat.size()- i - 1][i];
        }
        return mat.size() % 2 ? sum - mat[mat.size()/2][mat.size()/2] : sum;
    }
};