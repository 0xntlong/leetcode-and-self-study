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



function removeCoveredIntervals(intervals: number[][]): number {
    intervals.sort((a, b) => a[0] - b[0]);

    let [left, right] = intervals[0];
    let res = 1;

    for (const [x, y] of intervals) {
        if (x > left && y > right) {
            left = x;
            res++;
        }

        right = Math.max(right, y);
    }

    return res;
}