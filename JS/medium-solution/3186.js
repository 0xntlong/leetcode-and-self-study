/**
3186. Maximum Total Damage With Spell Casting
    A magician has various spells.
    You are given an array power, where each element represents the damage of a spell. Multiple spells can have the same damage value.
    It is a known fact that if a magician decides to cast a spell with a damage of power[i], they cannot cast any spell with a damage of power[i] - 2, power[i] - 1, power[i] + 1, or power[i] + 2.
    Each spell can be cast only once.
    Return the maximum possible total damage that a magician can cast.

    Example :
    Input: power = [1,1,3,4]
    Output: 6
    Explanation:
    The maximum possible damage of 6 is produced by casting spells 0, 1, 3 with damage 1, 1, 4.
*/



/**
 * @param {number[]} power
 * @return {number}
 */
var maximumTotalDamage = function(power) {
    const cnt = new Map();
    for (const x of power) 
        cnt.set(x, (cnt.get(x) || 0) + 1);

    const arr = Array.from(cnt.keys()).sort((a, b) => a - b);
    const n = arr.length;

    if (n === 1) 
        return arr[0] * cnt.get(arr[0]);

    const dp = new Array(n + 1).fill(0);
    dp[0] = 0;
    dp[1] = arr[0] * cnt.get(arr[0]);

    if (arr[1] - arr[0] > 2) {
        dp[2] = dp[1] + arr[1] * cnt.get(arr[1]);
    } else {
        dp[2] = Math.max(dp[1], arr[1] * cnt.get(arr[1]));
    }

    for (let i = 3; i <= n; i++) {
        const a_im1 = arr[i - 1], a_im2 = arr[i - 2], a_im3 = arr[i - 3];
        if ((a_im1 - a_im2 > 2) && (a_im1 - a_im3 > 2)) {
            dp[i] = dp[i - 1] + a_im1 * cnt.get(a_im1);
        } else if ((a_im1 - a_im3 > 2) && (a_im1 - a_im2 < 3)) {
            dp[i] = Math.max(dp[i - 2] + a_im1 * cnt.get(a_im1), dp[i - 1]);
        } else if ((a_im1 - a_im3 < 3) && (a_im1 - a_im2 < 3)) {
            dp[i] = Math.max(dp[i - 3] + a_im1 * cnt.get(a_im1), dp[i - 1]);
        }
    }
    return dp[n];
};