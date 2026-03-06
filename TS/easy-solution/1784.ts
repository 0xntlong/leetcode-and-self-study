/*
1784. Check if Binary String Has at Most One Segment of Ones
    Given a binary string s ​​​​​without leading zeros, return true​​​ if s contains at most one contiguous segment of ones. Otherwise, return false.

    Example :
    Input: s = "1001"
    Output: false
    Explanation: The ones do not form a contiguous segment.
*/


function checkOnesSegment(s: string): boolean {
    for (let i = 1; i < s.length; i++) {
        if (s[i - 1] === '0' && s[i] === '1') {
            return false;
        }
    }
    return true;
};