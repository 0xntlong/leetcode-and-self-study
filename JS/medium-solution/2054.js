/*
2054, Two Best Non-Overlapping Events 
    You are given a 0-indexed 2D integer array of events where events[i] = [startTimei, endTimei, valuei]. The ith event starts at startTimei and ends at endTimei, and if you attend this event, you will receive a value of valuei. You can choose at most two non-overlapping events to attend such that the sum of their values is maximized.
    Return this maximum sum.
    Note that the start time and end time is inclusive: that is, you cannot attend two events where one of them starts and the other ends at the same time. More specifically, if you attend an event with end time t, the next event must start at or after t + 1.

    Example :
    Input: events = [[1,3,2],[4,5,2],[2,4,3]]
    Output: 4
    Explanation: Choose the green events, 0 and 1 for a sum of 2 + 2 = 4.
*/



/**
 * @param {number[][]} events
 * @return {number}
 */
var maxTwoEvents = function(events) {
    events.sort((a, b) => (a[0] !== b[0]) ? a[0] - b[0] : a[1] - b[1]);

    const n = events.length;
    const starts = new Array(n);
    const suffix = new Array(n);

    for (let i = 0; i < n; i++) starts[i] = events[i][0];

    suffix[n - 1] = events[n - 1][2];
    for (let i = n - 2; i >= 0; i--) {
        suffix[i] = Math.max(suffix[i + 1], events[i][2]);
    }

    const lowerBound = (arr, target) => {
        let lo = 0, hi = arr.length;
        while (lo < hi) {
            const mid = (lo + hi) >> 1;
            if (arr[mid] < target) lo = mid + 1;
            else hi = mid;
        }
        return lo;
    };

    let res = 0;
    for (let i = 0; i < n; i++) {
        const idx = lowerBound(starts, events[i][1] + 1);
        let val = events[i][2];
        if (idx < n) val += suffix[idx];
        res = Math.max(res, val);
    }
    return res;
};