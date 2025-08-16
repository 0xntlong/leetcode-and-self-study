/**
1323. Maximum 69 Number
    You are given a positive integer num consisting only of digits 6 and 9.
    Return the maximum number you can get by changing at most one digit (6 becomes 9, and 9 becomes 6).
    Example :
    Input: num = 9669
    Output: 9969
    Explanation: 
    Changing the first digit results in 6669.
    Changing the second digit results in 9969.
    Changing the third digit results in 9699.
    Changing the fourth digit results in 9666.
    The maximum number is 9969.
 */




function maximum69Number (num: number): number {
    let s = num.toString().split('');
    for (let i = 0; i < s.length; i++){
        if (s[i] === '6'){
            s[i] = '9';
            break;
        }
    }
    return parseInt(s.join(''), 10);
};