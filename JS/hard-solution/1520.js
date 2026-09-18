/**
1520. Maximum Number of Non-Overlapping Substrings
    Given a string s of lowercase letters, you need to find the maximum number of non-empty substrings of s that meet the following conditions:
    The substrings do not overlap, that is for any two substrings s[i..j] and s[x..y], either j < x or i > y is true.
    A substring that contains a certain character c must also contain all occurrences of c.
    Find the maximum number of substrings that meet the above conditions. If there are multiple solutions with the same number of substrings, return the one with minimum total length. It can be shown that there exists a unique solution of minimum total length.
    Notice that you can return the substrings in any order.

    Example :
    Input: s = "adefaddaccc"
    Output: ["e","f","ccc"]
    Explanation: The following are all the possible substrings that meet the conditions:
    [
    "adefaddaccc"
    "adefadda",
    "ef",
    "e",
    "f",
    "ccc",
    ]
    If we choose the first string, we cannot choose anything else and we'd get only 1. If we choose "adefadda", we are left with "ccc" which is the only one that doesn't overlap, thus obtaining 2 substrings. Notice also, that it's not optimal to choose "ef" since it can be split into two. Therefore, the optimal way is to choose ["e","f","ccc"] which gives us 3 substrings. No other solution of the same number of substrings exist.
 */



/**
 * @param {string} s
 * @return {string[]}
 */
var maxNumOfSubstrings = function(s) {
    const count = new Array(26).fill(0);
    const first = new Array(26).fill(-1);
    const last = new Array(26).fill(-1);

    const order = [];

    for (let i = 0; i < s.length; i++) {
        const c = s.charCodeAt(i) - 97;

        if (count[c] === 0) {
            first[c] = i;
            order.push(c);
        }

        count[c]++;
        last[c] = i;
    }

    const res = [];
    let queue = [];

    for (const c of order) {
        queue.unshift([first[c], last[c], count[c]]);

        let left = Infinity;
        let right = -Infinity;
        let total = 0;

        for (const [x, y, z] of queue) {
            total += z;
            left = Math.min(left, x);
            right = Math.max(right, y);

            if (total === right - left + 1) {
                break;
            }
        }

        if (total === right - left + 1) {
            res.push(s.substring(left, right + 1));
            queue = [];
        }
    }

    return res;
};