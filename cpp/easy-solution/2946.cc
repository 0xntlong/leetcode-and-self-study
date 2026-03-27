/**
2946. Matrix Similarity After Cyclic Shifts
    You are given an m x n integer matrix mat and an integer k. The matrix rows are 0-indexed.
    The following proccess happens k times:
    Even-indexed rows (0, 2, 4, ...) are cyclically shifted to the left.
    Odd-indexed rows (1, 3, 5, ...) are cyclically shifted to the right.

    Return true if the final modified matrix after k steps is identical to the original matrix, and false otherwise.

    Example 1:
    Input: mat = [[1,2,3],[4,5,6],[7,8,9]], k = 4
    Output: false
    Explanation:
    In each step left shift is applied to rows 0 and 2 (even indices), and right shift to row 1 (odd index).
 */


#include <vector>
using namespace std;

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {
        int rows = mat.size();
        int cols = mat[0].size();
        k %= cols;
        if (k == 0) {
            return true;
        }
        
        for (int i = 0; i < rows; i++) {
            vector<int> shifted(mat[i].begin() + k, mat[i].end());
            shifted.insert(shifted.end(), mat[i].begin(), mat[i].begin() + k); 
            if (mat[i] != shifted) {
                return false;
            }
        }
        return true;
    }
};