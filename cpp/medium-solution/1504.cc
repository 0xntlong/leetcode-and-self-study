/**
1504. Count Submatrices With All Ones
    Given an m x n binary matrix mat, return the number of submatrices that have all ones.

    Example :
    Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
    Output: 13
    Explanation: 
    There are 6 rectangles of side 1x1.
    There are 2 rectangles of side 1x2.
    There are 3 rectangles of side 2x1.
    There is 1 rectangle of side 2x2. 
    There is 1 rectangle of side 3x1.
    Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
 */

#include <vector>
#include <utility> 
using namespace std;
class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> height(n, 0);
        long long ans = 0;
        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                height[j] = mat[i][j] ? height[j] + 1 : 0;
            }
            vector<pair<int, int>> st;
            long long cur = 0;
            for (int h : height){
                int cnt = 1;
                while (!st.empty() && st.back().first >= h){
                    cur -= 1LL * st.back().first * st.back().second;
                    cnt += st.back().second;
                    st.pop_back();
                }
                cur += 1LL * h * cnt;
                st.push_back({h, cnt});
                ans += cur;
            }
        }
        return (int)ans;
    }
};