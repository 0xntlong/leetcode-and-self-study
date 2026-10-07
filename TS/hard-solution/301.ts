/**
301. Remove Invalid Parentheses
    Given a string s that contains parentheses and letters, remove the minimum number of invalid parentheses to make the input string valid.
    Return a list of unique strings that are valid with the minimum number of removals. You may return the answer in any order.

    Example :
    Input: s = "()())()"
    Output: ["(())()","()()()"]
 */


function removeInvalidParentheses(s: string): string[] {
    const ans: string[] = [];

    const remove = (s: string, i: number, j: number, p: string[]): void => {
        let count = 0;

        for (let k = i; k < s.length; k++) {
            if (s[k] === p[0])
                count++;

            if (s[k] === p[1])
                count--;

            if (count < 0) {
                for (let x = j; x <= k; x++) {
                    if (
                        s[x] === p[1] &&
                        (x === j || s[x - 1] !== p[1])
                    ) {
                        remove(
                            s.slice(0, x) + s.slice(x + 1),
                            k,
                            x,
                            p
                        );
                    }
                }

                return;
            }
        }

        const rev = s.split("").reverse().join("");

        if (p[0] === "(") {
            remove(rev, 0, 0, [")", "("]);
        }
        else {
            ans.push(rev);
        }
    };

    remove(s, 0, 0, ["(", ")"]);

    return ans;
};