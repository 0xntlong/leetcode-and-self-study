/**
1190. Reverse Substrings Between Each Pair of Parentheses
    You are given a string s that consists of lower case English letters and brackets.
    Reverse the strings in each pair of matching parentheses, starting from the innermost one.
    Your result should not contain any brackets.
    Example :
    Input: s = "(abcd)"
    Output: "dcba"
 */


function reverseParentheses(s: string): string {
    const stack: string[] = [""];

    for (const ch of s) {
        if (ch === "(") {
            stack.push("");
        }
        else if (ch === ")") {
            const temp: string = stack.pop()!;

            stack[stack.length - 1] +=
                temp.split("").reverse().join("");
        }
        else {
            stack[stack.length - 1] += ch;
        }
    }

    return stack[0];
};