/**
3623. Count Number of Trapezoids I
    You are given a 2D integer array points, where points[i] = [xi, yi] represents the coordinates of the ith point on the Cartesian plane.
    A horizontal trapezoid is a convex quadrilateral with at least one pair of horizontal sides (i.e. parallel to the x-axis). Two lines are parallel if and only if they have the same slope.
    Return the number of unique horizontal trapezoids that can be formed by choosing any four distinct points from points.
    Since the answer may be very large, return it modulo 109 + 7.

    Example :
    Input: points = [[1,0],[2,0],[3,0],[2,2],[3,2]]
    Output: 3
    Explanation:
    There are three distinct ways to pick four points that form a horizontal trapezoid:
    Using points [1,0], [2,0], [3,2], and [2,2].
    Using points [2,0], [3,0], [3,2], and [2,2].
    Using points [1,0], [3,0], [3,2], and [2,2].
 */


#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        const int mod = 1e9 + 7;
        unordered_map<int, int> freq;
        for (const auto& p : points){
            freq[p[1]]++;
        }
        long long total = 0;
        long long pairs = 0;
        for (const auto& f : freq){
            if (f.second <= 1){
                continue;
            }
            long long pair = (long long)f.second * (f.second - 1) / 2;
            total += pair;
            pairs += pair * pair;
        }
        return (total * total - pairs) / 2 % mod;
    }
};