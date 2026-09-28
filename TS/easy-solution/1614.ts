/*
1614. Maximum Nesting Depth of the Parentheses
    Given a valid parentheses string s, return the nesting depth of s. The nesting depth is the maximum number of nested parentheses.

    Example :
    Input: s = "(1+(2*3)+((8)/4))+1"
    Output: 3
    Explanation:
    Digit 8 is inside of 3 nested parentheses in the string.
*/

function maxDepth(s: string): number {
    const stack: string[] = [];
    let depth: number = 0;

    for (let i = 0; i < s.length; i++) {
        if (s[i] === "(") {
            stack.push(s[i]);

            if (depth < stack.length) {
                depth = stack.length;
            }
        }
        else if (s[i] === ")") {
            stack.pop();
        }
    }

    return depth;

};