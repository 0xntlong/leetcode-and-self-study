/**
1353. Maximum Number of Events That Can Be Attended
    You are given an array of events where events[i] = [startDayi, endDayi]. Every event i starts at startDayi and ends at endDayi.
    You can attend an event i at any day d where startTimei <= d <= endTimei. You can only attend one event at any time d.
    Return the maximum number of events you can attend.

    Example :
    Input: events = [[1,2],[2,3],[3,4]]
    Output: 3
    Explanation: You can attend all the three events.
    One way to attend them all is as shown.
    Attend the first event on day 1.
    Attend the second event on day 2.
    Attend the third event on day 3.
 */



/**
 * @param {number[][]} events
 * @return {number}
 */
var maxEvents = function(events) {
    events.sort((a, b) => a[1] - b[1]);
    const lastDay = events[events.length - 1][1];
    const root = Array(lastDay + 2).fill(0).map((_, i) => i);
    const find = (i) => {
        if (root[i] !== i){
            root[i] = find(root[i]);
        }
        return root[i];
    };
    let res = 0;
    for (const [start, end] of events){
        let availableDay = find(start);
        if (availableDay <= end){
            res++;
            root[availableDay] = find(availableDay + 1);
        }
    }
    return res;
};