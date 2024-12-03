/*
1886. Determine Whether Matrix Can Be Obtained By Rotation
    Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.
    
    Example :
    Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
    Output: true
    Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
*/

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        if (mat == target){
            return true;
        }
        int deg = 3;
        while (deg--){
            for (int i = 0; i < n; i++){
                for (int j = i; j < n; j++){
                    swap(mat[i][j], mat[j][i]);
                }
            }
            for (int i = 0; i < n; i++){
                reverse(mat[i].begin(), mat[i].end());
            }
            if (mat == target){
                return true;
            }
        }
        return false;
    }
};