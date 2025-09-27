/**
812. Largest Triangle Area
    Given an array of points on the X-Y plane points where points[i] = [xi, yi], return the area of the largest triangle that can be formed by any three different points. Answers within 10-5 of the actual answer will be accepted.

    Example:

    Input: points = [[0,0],[0,1],[1,0],[0,2],[2,0]]
    Output: 2.00000
    Explanation: The five points are shown in the above figure. The red triangle is the largest.
 */



#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        double maxArea = 0;
        int n = points.size();
        for (int i = 0; i < n; i++){
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++){
                int x2 = points[j][0], y2 = points[j][1];
                for (int k = j + 1; k < n ; k++){
                    int x3 = points[k][0], y3 = points[k][1];
                    double curr = abs(0.5 * (x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)));
                    maxArea = max(maxArea, curr);
                }
            }
        }
        return maxArea;
    }
};