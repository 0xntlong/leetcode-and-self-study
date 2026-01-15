/**
3454. Separate Squares II
    You are given a 2D integer array squares. Each squares[i] = [xi, yi, li] represents the coordinates of the bottom-left point and the side length of a square parallel to the x-axis.
    Find the minimum y-coordinate value of a horizontal line such that the total area covered by squares above the line equals the total area covered by squares below the line.
    Answers within 10-5 of the actual answer will be accepted.
    Note: Squares may overlap. Overlapping areas should be counted only once in this version.

    Example :
    Input: squares = [[0,0,1],[2,2,1]]
    Output: 1.00000
    Explanation:
    Any horizontal line between y = 1 and y = 2 results in an equal split, with 1 square unit above and 1 square unit below. The minimum y-value is 1.
 */



#include <vector>
#include <tuple>
#include <algorithm>
using namespace std;

class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<tuple<long long,int,long long,long long>> events;
        for (auto& sq : squares) {
            long long x = sq[0], y = sq[1], length = sq[2];
            events.push_back({y, 1, x, x + length});
            events.push_back({y + length, -1, x, x + length});
        }

        sort(events.begin(), events.end());

        vector<pair<long long,long long>> active_intervals;
        long long prev_y = get<0>(events[0]);
        long long total_area = 0;
        vector<tuple<long long,long long,long long>> horizontal_slices;

        auto union_width = [&](vector<pair<long long,long long>>& intervals) -> long long {
            sort(intervals.begin(), intervals.end());
            long long total_width = 0;
            long long rightmost = (long long)-1e18;
            for (auto& it : intervals) {
                long long left = it.first, right = it.second;
                if (left > rightmost) {
                    total_width += right - left;
                    rightmost = right;
                } else if (right > rightmost) {
                    total_width += right - rightmost;
                    rightmost = right;
                }
            }
            return total_width;
        };

        for (auto& e : events) {
            long long y = get<0>(e);
            int event_type = get<1>(e);
            long long x_left = get<2>(e);
            long long x_right = get<3>(e);

            if (y > prev_y && !active_intervals.empty()) {
                long long height = y - prev_y;
                long long width = union_width(active_intervals);
                horizontal_slices.push_back({prev_y, height, width});
                total_area += height * width;
            }

            if (event_type == 1) {
                active_intervals.push_back({x_left, x_right});
            } else {
                auto it = find(active_intervals.begin(), active_intervals.end(), make_pair(x_left, x_right));
                if (it != active_intervals.end()) active_intervals.erase(it);
            }

            prev_y = y;
        }

        double half = (double)total_area / 2.0;
        double accumulated = 0.0;

        for (auto& hs : horizontal_slices) {
            long long start_y = get<0>(hs);
            long long height = get<1>(hs);
            long long width = get<2>(hs);

            double slice_area = (double)height * (double)width;
            if (accumulated + slice_area >= half) {
                return (double)start_y + (half - accumulated) / (double)width;
            }
            accumulated += slice_area;
        }

        return (double)prev_y;
    }
};