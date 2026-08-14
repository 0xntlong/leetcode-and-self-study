/**
3090. Maximum Length Substring With Two Occurrences
    Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
    Example :
    Input: s = "bcbbbcba"
    Output: 4
    Explanation:
    The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".
 */




/**
 * @param {string} s
 * @return {number}
 */
var maximumLengthSubstring = function(s) {
    const count = new Array(26).fill(0);
    let left = 0;
    let ans = 0;

    for (let right = 0; right < s.length; right++) {
        const idx = s.charCodeAt(right) - 97;
        count[idx]++;

        while (count[idx] > 2) {
            count[s.charCodeAt(left) - 97]--;
            left++;
        }

        ans = Math.max(ans, right - left + 1);
    }

    return ans;
};