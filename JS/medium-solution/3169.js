/**
3169. Count Days Without Meetings
    You are given a positive integer days representing the total number of days an employee is available for work (starting from day 1). You are also given a 2D array meetings of size n where, meetings[i] = [start_i, end_i] represents the starting and ending days of meeting i (inclusive).
    Return the count of days when the employee is available for work but no meetings are scheduled.
    Note: The meetings may overlap.
    Example :
    Input: days = 10, meetings = [[5,7],[1,3],[9,10]]
 */


/**
 * @param {number} days
 * @param {number[][]} meetings
 * @return {number}
 */
var countDays = function(days, meetings) {
    meetings.sort((a, b) => a[0] - b[0]);
    let res = 0;
    let end = 0;
    for (let i = 0; i < meetings.length; i++){
        const [start, finish] = meetings[i];
        if (start > end){
            res += start - end - 1;
        }
        end = Math.max(end, finish);
    }
    if (days > end){
        res += days - end;
    }
    return res;
};