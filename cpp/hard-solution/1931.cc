/*
1931. Painting a Grid With Three Different Colors
    You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.
    Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.Example :
    
    nput: m = 1, n = 1
    Output: 3
    Explanation: The three possible colorings are shown in the image above.
 */


#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    const int mod = 1e9 + 7;
    vector<int> state;
    vector<vector<int>> matrix;

    void DFS(int m, int pos, int prevColor, int mask){
        if (pos == m){
            state.push_back(mask);
            return;
        }
        for (int color = 0; color < 3; color++){
            if (color != prevColor){
                DFS(m, pos + 1, color, mask * 3 + color);
            }
        }
    }
    bool valid(int a, int b, int m){
        for (int i = 0; i < m; i++){
            if ((a % 3) == (b % 3))
                return false;
            a /= 3;
            b /= 3;
        }
        return true;
    }
    int colorTheGrid(int m, int n) {
        DFS(m , 0, -1, 0);
        int s = state.size();
        matrix.assign(s, vector<int>());
        for (int i = 0; i < s; i++){
            for (int j = 0; j < s; j++){
                if (valid(state[i], state[j], m)){
                    matrix[i].push_back(j);
                }
            }
        }
        vector<int> dp(s, 1);
        for (int col = 1; col < n; col++){
            vector<int> new_dp(s, 0);
            for (int i = 0; i < s; i++){
                for (int j : matrix[i]){
                    new_dp[j] = (new_dp[j] + dp[i]) % mod;
                }
            }
            dp = new_dp;
        }
        int res = 0; 
        for (int count : dp){
            res = (res + count) % mod;
        }
        return res;
    }
};