/**
22. Generate Parentheses
    Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
    Example :
    Input: n = 3
    Output: ["((()))","(()())","(())()","()(())","()()()"]
 */


/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    const result = [];

    function dfs(left, right, s) {
        if (s.length === n * 2) {
            result.push(s);
            return;
        }

        if (left < n) {
            dfs(left + 1, right, s + '(');
        }

        if (right < left) {
            dfs(left, right + 1, s + ')');
        }
    }

    dfs(0, 0, '');

    return result;
};