/**
3000. Maximum Area of Longest Diagonal Rectangle
    You are given a 2D 0-indexed integer array dimensions.
    For all indices i, 0 <= i < dimensions.length, dimensions[i][0] represents the length and dimensions[i][1] represents the width of the rectangle i.
    Return the area of the rectangle having the longest diagonal. If there are multiple rectangles with the longest diagonal, return the area of the rectangle having the maximum area.

    Example :
    Input: dimensions = [[9,3],[8,6]]
    Output: 48
    Explanation: 
    For index = 0, length = 9 and width = 3. Diagonal length = sqrt(9 * 9 + 3 * 3) = sqrt(90) ≈ 9.487.
    For index = 1, length = 8 and width = 6. Diagonal length = sqrt(8 * 8 + 6 * 6) = sqrt(100) = 10.
    So, the rectangle at index 1 has a greater diagonal length therefore we return area = 8 * 6 = 48.
 */


#include <vector>
using namespace std;
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int mx = 0;
        int mxDia = 0;
        for (auto& d : dimensions){
            int w = d[0], h = d[1];
            int dia = w*w + h*h;
            if (mxDia < dia){
                mxDia = dia;
                mx = 0;
            }
            if (dia == mxDia){
                mx = max(mx, w * h);
            }
        }
        return mx;
    }
};