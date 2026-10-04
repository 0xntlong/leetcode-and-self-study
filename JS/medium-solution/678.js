/**
678. Valid Parenthesis String
    Given a string s containing only three types of characters: '(', ')' and '*', return true if s is valid.
    The following rules define a valid string:
    Any left parenthesis '(' must have a corresponding right parenthesis ')'.
    Any right parenthesis ')' must have a corresponding left parenthesis '('.
    Left parenthesis '(' must go before the corresponding right parenthesis ')'.
    '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string "".

    Example :
    Input: s = "()"
    Output: true
 */


/**
 * @param {string} s
 * @return {boolean}
 */
var checkValidString = function(s) {
    const left = [];
    const star = [];
    const n = s.length;

    for (let i = 0; i < n; i++) {
        if (s[i] === '(') {
            left.push(i);
        }
        else if (s[i] === '*') {
            star.push(i);
        }
        else if (s[i] === ')') {
            if (left.length > 0) {
                left.pop();
            }
            else if (star.length > 0) {
                star.pop();
            }
            else {
                return false;
            }
        }
    }

    while (
        left.length > 0 &&
        star.length > 0 &&
        left[left.length - 1] < star[star.length - 1]
    ) {
        left.pop();
        star.pop();
    }

    if (left.length > 0) {
        return false;
    }

    return true;
};