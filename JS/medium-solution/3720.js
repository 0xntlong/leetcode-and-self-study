/**
3720. Lexicographically Smallest Permutation Greater Than Target
    You are given two strings s and target, both having length n, consisting of lowercase English letters.
    Return the lexicographically smallest permutation of s that is strictly greater than target. If no permutation of s is lexicographically strictly greater than target, return an empty string.
    A string a is lexicographically strictly greater than a string b (of the same length) if in the first position where a and b differ, string a has a letter that appears later in the alphabet than the corresponding letter in b.

    Example :
    Input: s = "abc", target = "bba"
    Output: "bca"
    Explanation:
    The permutations of s (in lexicographical order) are "abc", "acb", "bac", "bca", "cab", and "cba".
    The lexicographically smallest permutation that is strictly greater than target is "bca".
 */



/**
 * @param {string} s
 * @param {string} target
 * @return {string}
 */
var lexGreaterPermutation = function(s, target) {
    const n = s.length;

    const cnt = new Array(26).fill(0);

    for (const ch of s) {
        cnt[ch.charCodeAt(0) - 97]++;
    }

    let p = 0;

    while (p < n) {
        const c = target.charCodeAt(p) - 97;

        if (cnt[c] === 0) {
            break;
        }

        cnt[c]--;
        p++;
    }

    let i = p;

    while (i >= 0) {
        if (i < n) {
            const t = target.charCodeAt(i) - 97;
            let pick = -1;

            for (let c = t + 1; c < 26; c++) {
                if (cnt[c] > 0) {
                    pick = c;
                    break;
                }
            }

            if (pick >= 0) {
                cnt[pick]--;

                let tail = "";

                for (let c = 0; c < 26; c++) {
                    tail += String.fromCharCode(97 + c).repeat(cnt[c]);
                }

                cnt[pick]++;

                return target.slice(0, i)
                    + String.fromCharCode(97 + pick)
                    + tail;
            }
        }

        i--;

        if (i >= 0) {
            cnt[target.charCodeAt(i) - 97]++;
        }
    }

    return "";
};