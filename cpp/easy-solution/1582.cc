/*
1582. Special Positions in a Binary Matrix
    Given an m x n binary matrix mat, return the number of special positions in mat.
    A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

    Example :
    Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
    Output: 1
    Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
*/

#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int special = 0;
        unordered_map<int, int> x;
        unordered_map<int, int> y;
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (mat[i][j] == 1){
                    x[i]++;
                    y[j]++;
                }
            }
        }
        for (int i = 0; i < rows; i++){
            for (int j = 0; j < cols; j++){
                if (x.find(i) != x.end() && y.find(j) != y.end()){
                    if (x[i] == 1 && y[j] == 1){
                        if (mat[i][j] == 1)
                            special++;
                    }
                }
            }
        }
        return special;
    }
};