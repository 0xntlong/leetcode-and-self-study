/**
1751. Maximum Number of Events That Can Be Attended II
    You are given an array of events where events[i] = [startDayi, endDayi, valuei]. The ith event starts at startDayi and ends at endDayi, and if you attend this event, you will receive a value of valuei. You are also given an integer k which represents the maximum number of events you can attend.
    You can only attend one event at a time. If you choose to attend an event, you must attend the entire event. Note that the end day is inclusive: that is, you cannot attend two events where one of them starts and the other ends on the same day.
    Return the maximum sum of values that you can receive by attending events.

    Example :
    Input: events = [[1,2,4],[3,4,3],[2,3,1]], k = 2
    Output: 7
    Explanation: Choose the green events, 0 and 1 (0-indexed) for a total value of 4 + 3 = 7.
 */



function maxValue(events: number[][], k: number): number {
    events.sort((a, b) => a[0] - b[0]);
    const n = events.length;
    const starts = events.map(e => e[0]);
    const next_idx = new Array(n).fill(0);
    for (let i = 0; i < n; i++){
        let l = i + 1;
        let r = n;
        while (l < r){
            let m = Math.floor((l + r) / 2);
            if (starts[m] > events[i][1])
                r = m;
            else 
                l = m + 1;
        }
        next_idx[i] = l;
    }
    const dp = Array.from({length : 2}, () => new Array(n + 1).fill(0));
    for (let j = 1; j <= k; j++){
        const cur = j % 2;
        const prev = (j - 1) % 2;
        for (let i = n - 1; i >= 0; i--){
            const attend = events[i][2] + dp[prev][next_idx[i]];
            const skip = dp[cur][i + 1];
            dp[cur][i] = Math.max(attend, skip);
        }
    }
    return dp[k % 2][0];
};