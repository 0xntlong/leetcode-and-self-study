/*
1415. The k-th Lexicographical String of All Happy Strings of Length n
    A happy string is a string that:
    consists only of letters of the set ['a', 'b', 'c'].
    s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
    For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.
    Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.
    Return the kth string of this list or return an empty string if there are less than k happy strings of length n.

    Example :
    Input: n = 1, k = 3
    Output: "c"
    Explanation: The list ["a", "b", "c"] contains all happy strings of length 1. The third string is "c".
*/

function getHappyString(n: number, k: number): string {
    const total = 3 * (1 << (n - 1));

    if (k > total) {
        return "";
    }

    const s: string[] = ['a', 'b', 'c'];
    let res = '';
    k -= 1;

    for (let i = 0; i < n; i++) {
        const block = 1 << (n - i - 1);
        let index = Math.floor(k / block);

        for (let c of s) {
            if (res.length === 0 || c !== res[res.length - 1]) {
                if (index === 0) {
                    res += c;
                    break;
                }
                index -= 1;
            }
        }
        k %= block;
    }

    return res;
};
