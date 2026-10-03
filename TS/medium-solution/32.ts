/**
32. Longest Valid Parentheses
    Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
    Example :
    Input: s = "(()"
    Output: 2
    Explanation: The longest valid parentheses substring is "()".
 */


function longestValidParentheses(s: string): number {
    const stack: number[] = [-1];
    let max_len: number = 0;

    for (let i = 0; i < s.length; i++) {
        if (s[i] === "(") {
            stack.push(i);
        }
        else {
            stack.pop();

            if (stack.length === 0) {
                stack.push(i);
            }
            else {
                max_len = Math.max(
                    max_len,
                    i - stack[stack.length - 1]
                );
            }
        }
    }

    return max_len;
};