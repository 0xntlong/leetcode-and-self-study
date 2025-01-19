/*
407. Trapping Rain Water II
    Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.
    
    Example :
    Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
    Output: 4
    Explanation: After the rain, water is trapped between the blocks.
    We have two small ponds 1 and 3 units trapped.
    The total volume of water trapped is 4.
*/

#include <vector>
#include <queue>
#include <iostream>
using namespace std;
class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        vector<vector<int>> vol(m, vector<int>(n));
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                vol[i][j] = heightMap[i][j];
            }
        }
        bool upt = true, init = true;
        while (upt){
            upt = false;
            for (int i = 1; i < m - 1; i++){
                for (int j = 1; j < n - 1; j++){
                    int val = max(heightMap[i][j], min(vol[i - 1][j], vol[i][j - 1]));
                    if (init || vol[i][j] > val){
                        vol[i][j] = val;
                        upt = true;
                    }
                }
            }
            init = false;
            for (int i = m - 2; i>= 1; i--){
                for (int j = n - 2; j >= 1; j--){
                    int val = max(heightMap[i][j], min(vol[i + 1][j], vol[i][j + 1]));
                    if (vol[i][j] > val){
                        vol[i][j] = val;
                        upt = true;
                    }
                }
            }
        }
        int res = 0;
        for (int i = 1; i < m - 1; i++){
            for (int j = 1; j < n - 1; j++){
                if (vol[i][j] > heightMap[i][j]){
                    res += vol[i][j] - heightMap[i][j];
                }
            }
        }
        return res;
    }
};