/**
85. Maximal Rectangle
    Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

    Example :
    Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    Output: 6
    Explanation: The maximal rectangle is shown in the above picture.
*/


#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        if (row == 0 && col == 0){
            return 0;
        }
        vector<vector<int>> dp(row, vector<int>(col, 0));
        for (int i = 0; i < row; i++){
            for (int j = 0; j < col; j++){
                int v = matrix[i][j] - '0';
                if (v == 1){
                    dp[i][j] = v + (i > 0 ? dp[i - 1][j] : 0);
                }
            }
        }
        auto calculate = [&](const vector<int>& heights) -> int {
            vector<pair<int, int>> st;
            int maxArea = 0;
            int n = (int)heights.size();
            for (int i = 0; i < n; i++){
                int start = i;
                while (!st.empty() && st.back().first > heights[i]){
                    auto [val, idx] = st.back();
                    st.pop_back();
                    maxArea = max(maxArea, val * (i - idx));
                    start = idx;
                }
                st.push_back({heights[i], start});
            }
            while (!st.empty()){
                auto [val, idx] = st.back();
                st.pop_back();
                maxArea = max(maxArea, val * (n - idx));
            }
            return maxArea;
        };
        int ans = 0;
        for (int i = 0; i < row; i++){
            ans = max(ans, calculate(dp[i]));
        }
        return ans;
    }
};