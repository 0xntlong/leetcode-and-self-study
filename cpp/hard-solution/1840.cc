/**
1840. Maximum Building Height
    You want to build n new buildings in a city. The new buildings will be built in a line and are labeled from 1 to n.
    However, there are city restrictions on the heights of the new buildings:
    The height of each building must be a non-negative integer.
    The height of the first building must be 0.
    The height difference between any two adjacent buildings cannot exceed 1.
    Additionally, there are city restrictions on the maximum height of specific buildings. These restrictions are given as a 2D integer array restrictions where restrictions[i] = [idi, maxHeighti] indicates that building idi must have a height less than or equal to maxHeighti.
    It is guaranteed that each building will appear at most once in restrictions, and building 1 will not be in restrictions.
    Return the maximum possible height of the tallest building.

    Example :
    Input: n = 5, restrictions = [[2,1],[4,1]]
    Output: 2
    Explanation: The green area in the image indicates the maximum allowed height for each building.
    We can build the buildings with heights [0,1,2,1,2], and the tallest building has a height of 2.
 */


#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxBuilding(int n, vector<vector<int>>& restrictions) {
        if (restrictions.empty()) {
            return n - 1;
        }
        sort(restrictions.begin(), restrictions.end());
        int idx = 1, h = 0;
        for (int i = 0; i < restrictions.size(); i++) {
            int x = restrictions[i][0];
            int y = restrictions[i][1];
            restrictions[i][1] = min(y, x - idx + h);
            idx = x;
            h = restrictions[i][1];
        }
        for (int i = restrictions.size() - 2; i >= 0; i--) {
            restrictions[i][1] = min(
                restrictions[i][1],
                restrictions[i + 1][1] + restrictions[i + 1][0] - restrictions[i][0]
            );
        }
        int res = n - restrictions.back()[0] + restrictions.back()[1];
        idx = 1;
        h = 0;
        for (auto& r : restrictions) {
            int x = r[0];
            int y = r[1];
            int steps = x - idx - abs(y - h);
            int higher = max(y, h);
            res = max(res, higher + steps / 2);
            idx = x;
            h = y;
        }
        return res;
    }
};