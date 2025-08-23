/*
3197. Find the Minimum Area to Cover All Ones II
    You are given a 2D binary array grid. You need to find 3 non-overlapping rectangles having non-zero areas with horizontal and vertical sides such that all the 1's in grid lie inside these rectangles.
    Return the minimum possible sum of the area of these rectangles.
    Note that the rectangles are allowed to touch.

    Example :
    Input: grid = [[1,0,1],[1,1,1]]
    Output: 5
    Explanation:
    The 1's at (0, 0) and (1, 0) are covered by a rectangle of area 2.
    The 1's at (0, 2) and (1, 2) are covered by a rectangle of area 2.
    The 1 at (1, 1) is covered by a rectangle of area 1.
*/


#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int minimumSum(vector<vector<int>>& grid) {
        long long res = (long long)4e18;
        vector<vector<int>> A = grid;
        for (int rot = 0; rot < 4; rot++) {
            int m = (int)A.size(), n = (int)A[0].size();
            for (int i = 1; i < m; i++) {
                int topArea = area(submatrixRows(A, 0, i)); 
                for (int j = 1; j < n; j++) {
                    auto left  = submatrixCols(A, i, m, 0, j);     
                    auto right = submatrixCols(A, i, m, j, n);     
                    int a2 = area(left), a3 = area(right);
                    res = min(res, (long long)topArea + a2 + a3);
                }
                for (int k = i + 1; k < m; k++) {
                    auto mid = submatrixRows(A, i, k);  
                    auto bot = submatrixRows(A, k, m);   
                    int a2 = area(mid), a3 = area(bot);
                    res = min(res, (long long)topArea + a2 + a3);
                }
            }
            A = rotate(A);
        }
        return (int)res;
    }
private:
    static vector<vector<int>> submatrixRows(const vector<vector<int>>& g, int r1, int r2) {
        if (r1 >= r2) return {};
        vector<vector<int>> out(g.begin() + r1, g.begin() + r2);
        return out;
    }
    static vector<vector<int>> submatrixCols(const vector<vector<int>>& g, int r1, int r2, int c1, int c2) {
        if (r1 >= r2 || c1 >= c2) return {};
        vector<vector<int>> out;
        out.reserve(r2 - r1);
        for (int i = r1; i < r2; i++) {
            vector<int> row;
            row.reserve(c2 - c1);
            for (int j = c1; j < c2; j++) row.push_back(g[i][j]);
            out.push_back(move(row));
        }
        return out;
    }
    static int area(const vector<vector<int>>& g) {
        if (g.empty() || g[0].empty()) return 0;
        int m = (int)g.size(), n = (int)g[0].size();
        int left = INT_MAX, top = INT_MAX, right = -1, bottom = -1;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (g[i][j] == 1) {
                    left = min(left, j);
                    right = max(right, j);
                    top = min(top, i);
                    bottom = max(bottom, i);
                }
        if (right == -1) return 0;
        return (right - left + 1) * (bottom - top + 1);
    }
    static vector<vector<int>> rotate(const vector<vector<int>>& g) {
        int m = (int)g.size(), n = (int)g[0].size();
        vector<vector<int>> r(n, vector<int>(m));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                r[j][m - 1 - i] = g[i][j];
        return r;
    }
};