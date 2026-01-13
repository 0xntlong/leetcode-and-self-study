/**
3453. Separate Squares I
    You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.
    Find the minimum y-coordinate value of a horizontal line such that the total area of the squares above the line equals the total area of the squares below the line.
    Answers within 10-5 of the actual answer will be accepted.
    Note: Squares may overlap. Overlapping areas should be counted multiple times.

    Example :
    Input: squares = [[0,0,1],[2,2,1]]
    Output: 1.00000
    Explanation:
    Any horizontal line between y = 1 and y = 2 will have 1 square unit above it and 1 square unit below it. The lowest option is 1.
 */

#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        long long total = 0;
        unordered_map<long long, long long> diff;
        for (auto& sq : squares){
            long long y = sq[1];
            long long s = sq[2];
            total += s * s;
            diff[y] += s;
            diff[y + s] -= s;
        }
        vector<long long> curr;
        curr.reserve(diff.size());
        for (auto& k : diff){
            curr.push_back(k.first);
        }
        sort(curr.begin(), curr.end());
        long long area = 0;
        long long target = 0;
        for (int i = 0; i + 1 < (int)curr.size(); i++){
            long long y = curr[i];
            long long y2 = curr[i + 1];
            target += diff[y];
            area += target * (y2 - y);
            if (area * 2 >= total){
                return (double)y2 - (double)(area * 2 - total) / (double)(target * 2);
            }
        }
        return (double)curr.back();
    }
};