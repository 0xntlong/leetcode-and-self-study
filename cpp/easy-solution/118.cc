/*
118. Pascal's Triangle
    Given an integer numRows, return the first numRows of Pascal's triangle.

    In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

    Example :
    Input: numRows = 5
    Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/

#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> temp(numRows);
        for (int i = 0; i < numRows; i++){
            temp[i].assign(i+1, 1);
            for (int j = 1; j <= i / 2; j++){
                temp[i][i - j] = temp[i][j] = temp[i - 1][j - 1] + temp[i - 1][j];
            }
        }
        return temp;

    }
};