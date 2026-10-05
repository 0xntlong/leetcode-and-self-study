/**
856. Score of Parentheses
    Given a balanced parentheses string s, return the score of the string.
    The score of a balanced parentheses string is based on the following rule:
    "()" has score 1.
    AB has score A + B, where A and B are balanced parentheses strings.
    (A) has score 2 * A, where A is a balanced parentheses string.
    Example :
    Input: s = "()"
    Output: 1
 */



function scoreOfParentheses(s: string): number {
    const stack: number[] = [0];

    for (const c of s) {
        if (c === '(') {
            stack.push(0);
        }
        else {
            const value = Math.max(2 * stack.pop()!, 1);
            stack[stack.length - 1] += value;
        }
    }

    return stack.pop()!;
};