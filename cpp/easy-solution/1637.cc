/*
1637. Widest Vertical Area Between Two Points Containing No Points
    Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.
    A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.
    Note that points on the edge of a vertical area are not considered included in the area.


    Example :
    Input: points = [[8,7],[9,9],[7,4],[9,7]]
    Output: 1
    Explanation: Both the red and the blue area are optimal.
*/

#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int Max = 0;
        for ( int i = 1; i < points.size(); i++){
            int wid = points[i][0] - points[i - 1][0];
            Max = max(Max, wid);
        }
        return Max;
    }
};