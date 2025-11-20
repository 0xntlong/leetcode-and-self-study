/**
757. Set Intersection Size At Least Two
    You are given a 2D integer array intervals where intervals[i] = [starti, endi] represents all the integers from starti to endi inclusively.
    A containing set is an array nums where each interval from intervals has at least two integers in nums.
    For example, if intervals = [[1,3], [3,7], [8,9]], then [1,2,4,7,8,9] and [2,3,4,8,9] are containing sets.
    Return the minimum possible size of a containing set.
    
    Example :
    Input: intervals = [[1,3],[3,7],[8,9]]
    Output: 5
    Explanation: let nums = [2, 3, 4, 8, 9].
    It can be shown that there cannot be any containing array of size 4.
 */



/**
 * @param {number[][]} intervals
 * @return {number}
 */
var intersectionSizeTwo = function(intervals) {
    intervals.sort((a, b) =>
        a[1] === b[1] ? b[0] - a[0] : a[1] - b[1]
    );
    let cnt = 0;
    let first = -1, second = -1;
    for (let [start, end] of intervals){
        let first_in = first >= start;
        let second_in = second >= start;
        if (first_in && second_in)
            continue;
        if (!first_in && !second_in){
            cnt += 2;
            second = end;
            first = end - 1;
        } else {
            cnt += 1;
            first = second;
            second = end;
        }
    }
    return cnt;
};