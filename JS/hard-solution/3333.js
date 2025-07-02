/**
3333. Find the Original Typed String II
    Alice is attempting to type a specific string on her computer. However, she tends to be clumsy and may press a key for too long, resulting in a character being typed multiple times.
    You are given a string word, which represents the final output displayed on Alice's screen. You are also given a positive integer k.
    Return the total number of possible original strings that Alice might have intended to type, if she was trying to type a string of size at least k.
    Since the answer may be very large, return it modulo 109 + 7.

    Example 1:
    Input: word = "aabbccdd", k = 7
    Output: 5
    Explanation:
    The possible strings are: "aabbccdd", "aabbccd", "aabbcdd", "aabccdd", and "abbccdd".
 */



/**
 * @param {string} word
 * @param {number} k
 * @return {number}
 */
var possibleStringCount = function(word, k) {
    const mod = 1e9 + 7;
    const cnt = [];
    let total = 1;
    const n = word.length;
    let i = 0;
    while (i < n){
        let j = i;
        while (i < n && word[i] === word[j]){
            i++;
        }
        let len = i - j;
        if (len > 0){
            cnt.push(len - 1);
            total = total * len % mod;
        }
        k--;
    }
    if (k <= 0)
        return total;
    const dp = Array(k).fill(0);
    dp[0] = 1;
    for (const c of cnt){
        for (let i = 1; i < k; i++){
            dp[i] = (dp[i] + dp[i - 1]) % mod;
        }
        for (let i = k - 1; i > c; i--){
            dp[i] = (dp[i] - dp[i - c - 1] + mod) % mod;
        }
    }
    for (let i = 1; i < k; i++){
        dp[i] = (dp[i] + dp[i - 1]) % mod;
    }
    let ans = (total - dp[k - 1] + mod) % mod;
    return ans;
};