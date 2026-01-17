/**
3047. Find the Largest Area of Square Inside Two Rectangles
    There exist n rectangles in a 2D plane with edges parallel to the x and y axis. You are given two 2D integer arrays bottomLeft and topRight where bottomLeft[i] = [a_i, b_i] and topRight[i] = [c_i, d_i] represent the bottom-left and top-right coordinates of the ith rectangle, respectively.
    You need to find the maximum area of a square that can fit inside the intersecting region of at least two rectangles. Return 0 if such a square does not exist.
    Example :
    Input: bottomLeft = [[1,1],[2,2],[3,1]], topRight = [[3,3],[4,4],[6,6]]
    Output: 1
    Explanation:
    A square with side length 1 can fit inside either the intersecting region of rectangles 0 and 1 or the intersecting region of rectangles 1 and 2. Hence the maximum area is 1. It can be shown that a square with a greater side length can not fit inside any intersecting region of two rectangles.
 */

#include <vector>

using namespace std;

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        long long maxSquare = 0;
        for (int i = 0; i < n - 1; i++){
            for (int j = i + 1; j < n; j++){
                long long min_x = max(bottomLeft[i][0], bottomLeft[j][0]);
                long long max_x = min(topRight[i][0], topRight[j][0]);
                long long min_y = max(bottomLeft[i][1], bottomLeft[j][1]);
                long long max_y = min(topRight[i][1], topRight[j][1]);
                if (min_x < max_x && min_y < max_y){
                    long long square = min(max_x - min_x, max_y - min_y);
                    maxSquare = max(maxSquare, square * square);
                }
            }
        }
        return maxSquare;
    }
};