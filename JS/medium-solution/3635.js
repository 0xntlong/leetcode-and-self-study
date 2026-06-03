/**
3635. Earliest Finish Time for Land and Water Rides II
    You are given two categories of theme park attractions: land rides and water rides.

    Land rides
    landStartTime[i] – the earliest time the ith land ride can be boarded.
    landDuration[i] – how long the ith land ride lasts.
    Water rides
    waterStartTime[j] – the earliest time the jth water ride can be boarded.
    waterDuration[j] – how long the jth water ride lasts.
    A tourist must experience exactly one ride from each category, in either order.
    A ride may be started at its opening time or any later moment.
    If a ride is started at time t, it finishes at time t + duration.
    Immediately after finishing one ride the tourist may board the other (if it is already open) or wait until it opens.
    Return the earliest possible time at which the tourist can finish both rides.

    Example :
    Input: landStartTime = [2,8], landDuration = [4,1], waterStartTime = [6], waterDuration = [3]
    Output: 9
    Explanation:​​​​​​​
    Plan A (land ride 0 → water ride 0):
    Start land ride 0 at time landStartTime[0] = 2. Finish at 2 + landDuration[0] = 6.
    Water ride 0 opens at time waterStartTime[0] = 6. Start immediately at 6, finish at 6 + waterDuration[0] = 9.
    Plan B (water ride 0 → land ride 1):
    Start water ride 0 at time waterStartTime[0] = 6. Finish at 6 + waterDuration[0] = 9.
    Land ride 1 opens at landStartTime[1] = 8. Start at time 9, finish at 9 + landDuration[1] = 10.
    Plan C (land ride 1 → water ride 0):
    Start land ride 1 at time landStartTime[1] = 8. Finish at 8 + landDuration[1] = 9.
    Water ride 0 opened at waterStartTime[0] = 6. Start at time 9, finish at 9 + waterDuration[0] = 12.
    Plan D (water ride 0 → land ride 0):
    Start water ride 0 at time waterStartTime[0] = 6. Finish at 6 + waterDuration[0] = 9.
    Land ride 0 opened at landStartTime[0] = 2. Start at time 9, finish at 9 + landDuration[0] = 13.
    Plan A gives the earliest finish time of 9.
 */


/**
 * @param {number[]} landStartTime
 * @param {number[]} landDuration
 * @param {number[]} waterStartTime
 * @param {number[]} waterDuration
 * @return {number}
 */
var earliestFinishTime = function(landStartTime, landDuration, waterStartTime, waterDuration) {
    const calculate = (start1, dur1, start2, dur2) => {
        let firstEnd = Infinity;
        for (let i = 0; i < start1.length; i++) {
            firstEnd = Math.min(firstEnd, start1[i] + dur1[i]);
        }
        let ans = Infinity;
        for (let i = 0; i < start2.length; i++) {
            ans = Math.min(ans, Math.max(firstEnd, start2[i]) + dur2[i]);
        }
        return ans;
    };


    const landFirst = calculate(landStartTime, landDuration, waterStartTime, waterDuration);

    const waterFirst = calculate(waterStartTime, waterDuration, landStartTime, landDuration);
    
    return Math.min(landFirst, waterFirst);
};