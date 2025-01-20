/*
2661. First Completely Painted Row or Column
    You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].
    Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].
    Return the smallest index i at which either a row or a column will be completely painted in mat.
    Example :
    image explanation for example 1
    Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
    Output: 2
    Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
*/


#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        const int m = mat.size(), n = mat[0].size(), N = m * n;
        vector<int> to_i(N + 1), to_j(N + 1);
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                int matrix = mat[i][j];
                to_i[matrix] = i;
                to_j[matrix] = j;
            }
        }
        vector<int> row(m, 0), col(n, 0);
        for (int i = 0; i < N; i++){
            int x = arr[i];
            if (++row[to_i[x]] == n || ++col[to_j[x]] == m){
                return i;
            }
        }
        return -1;
    }
};