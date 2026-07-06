/**
1288. Remove Covered Intervals
    Given an array intervals where intervals[i] = [li, ri] represent the interval [li, ri), remove all intervals that are covered by another interval in the list.
    The interval [a, b) is covered by the interval [c, d) if and only if c <= a and b <= d.
    Return the number of remaining intervals.
    Example :
    Input: intervals = [[1,4],[3,6],[2,8]]
    Output: 2
    Explanation: Interval [3,6] is covered by [2,8], therefore it is removed.
 */


class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int left = intervals[0][0];
        int right = intervals[0][1];
        int res = 1;
        for (auto& interval : intervals) {
            int x = interval[0];
            int y = interval[1];
            if (x > left && y > right) {
                left = x;
                res++;
            }
            right = max(right, y);
        }
        return res;
    }
};