/**
 * 20. Valid Parentheses
 * Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
 * An input string is valid if:
 * Open brackets must be closed by the same type of brackets.
 * Open brackets must be closed in the correct order.
 * Every close bracket has a corresponding open bracket of the same type.
 * 
 * Example:
 * Input: s = "()"
 * Output: true
 */


/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function(s) {
    const a = [];

    for (let i = 0; i < s.length; i++) {
        if (s[i] === "(" || s[i] === "[" || s[i] === "{") {
            a.push(s[i]);
        }
        else {
            if (a.length === 0) {
                return false;
            }

            const top = a.pop();

            if (s[i] === ")" && top !== "(")
                return false;

            if (s[i] === "]" && top !== "[")
                return false;

            if (s[i] === "}" && top !== "{")
                return false;
        }
    }

    return a.length === 0;
};