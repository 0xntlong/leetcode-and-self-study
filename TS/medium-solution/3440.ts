/*
3440. Reschedule Meetings for Maximum Free Time II
    You are given an integer eventTime denoting the duration of an event. You are also given two integer arrays startTime and endTime, each of length n.
    These represent the start and end times of n non-overlapping meetings that occur during the event between time t = 0 and time t = eventTime, where the ith meeting occurs during the time [startTime[i], endTime[i]].
    You can reschedule at most one meeting by moving its start time while maintaining the same duration, such that the meetings remain non-overlapping, to maximize the longest continuous period of free time during the event.
    Return the maximum amount of free time possible after rearranging the meetings.
    Note that the meetings can not be rescheduled to a time outside the event and they should remain non-overlapping.
    Note: In this version, it is valid for the relative ordering of the meetings to change after rescheduling one meeting.

    Example 1:
    Input: eventTime = 5, startTime = [1,3], endTime = [2,5]
    Output: 2
    Explanation:
    Reschedule the meeting at [1, 2] to [2, 3], leaving no meetings during the time [0, 2].
 */


    function maxFreeTime(eventTime: number, startTime: number[], endTime: number[]): number {
    const n = startTime.length;
    const gap: number[] = new Array(n + 1).fill(0);
    let lastEnd = 0;

    for (let i = 0; i < n; i++) {
        gap[i] = startTime[i] - lastEnd;
        lastEnd = endTime[i];
    }
    gap[n] = eventTime - lastEnd;

    const rightMax: number[] = new Array(n + 1).fill(0);
    for (let i = n - 1; i >= 0; i--) {
        rightMax[i] = Math.max(rightMax[i + 1], gap[i + 1]);
    }

    let leftMax = 0;
    let maxGap = 0;

    for (let i = 1; i <= n; i++) {
        const dur = endTime[i - 1] - startTime[i - 1];
        const gapL = gap[i - 1];
        const gapR = gap[i];

        if (leftMax >= dur || rightMax[i] >= dur) {
            maxGap = Math.max(maxGap, gapL + dur + gapR);
        }
        maxGap = Math.max(maxGap, gapL + gapR);
        leftMax = Math.max(leftMax, gapL);
    }

    return maxGap;
}