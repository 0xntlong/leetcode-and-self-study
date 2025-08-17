/**
837. New 21 Game
    Alice plays the following game, loosely based on the card game "21".
    Alice starts with 0 points and draws numbers while she has less than k points. During each draw, she gains an integer number of points randomly from the range [1, maxPts], where maxPts is an integer. Each draw is independent and the outcomes have equal probabilities.
    Alice stops drawing numbers when she gets k or more points.
    Return the probability that Alice has n or fewer points.
    Answers within 10-5 of the actual answer are considered accepted.

    Example :
    Input: n = 10, k = 1, maxPts = 10
    Output: 1.00000
    Explanation: Alice gets a single card, then stops.
 */



/**
 * @param {number} n
 * @param {number} k
 * @param {number} maxPts
 * @return {number}
 */
var new21Game = function(n, k, maxPts) {
    if (k === 0 || n >= k - 1 + maxPts)
        return 1.0;
    if (n < k)
        return 0.0;
    const dp = new Array(n + 1).fill(0.0);
    for (let i = 1; i <= n; i++){
        dp[i] = 1.0;
    }
    const right = Math.min(n, k + maxPts - 1);
    let window = 0.0;
    for (let i = k; i <= right; i++){
        window += dp[i];
    }
    for (let i = k - 1; i >= 0; i--){
        dp[i] = window / maxPts;
        window += dp[i];
        if (i + maxPts <= n)
            window -= dp[i + maxPts];
    }
    return dp[0];
};