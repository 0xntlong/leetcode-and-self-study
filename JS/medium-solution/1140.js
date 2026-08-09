/**
1140. Stone Game II
    Alice and Bob continue their games with piles of stones. There are a number of piles arranged in a row, and each pile has a positive integer number of stones piles[i]. The objective of the game is to end with the most stones.
    Alice and Bob take turns, with Alice starting first.
    On each player's turn, that player can take all the stones in the first X remaining piles, where 1 <= X <= 2M. Then, we set M = max(M, X). Initially, M = 1.
    The game continues until all the stones have been taken.
    Assuming Alice and Bob play optimally, return the maximum number of stones Alice can get.
    Example :
    Input: piles = [2,7,9,4,4]
    Output: 10
    Explanation:
    If Alice takes one pile at the beginning, Bob takes two piles, then Alice takes 2 piles again. Alice can get 2 + 4 + 4 = 10 stones in total.
    If Alice takes two piles at the beginning, then Bob can take all three piles left. In this case, Alice get 2 + 7 = 9 stones in total.
    So we return 10 since it's larger.
*/



/**
 * @param {number[]} piles
 * @return {number}
 */
var stoneGameII = function(piles) {
    const n = piles.length;

    const dp = Array.from(
        { length: n },
        () => new Array(n + 1).fill(0)
    );

    const suffixSum = new Array(n).fill(0);

    suffixSum[n - 1] = piles[n - 1];

    for (let x = n - 2; x >= 0; x--) {
        suffixSum[x] = suffixSum[x + 1] + piles[x];
    }

    for (let x = n - 1; x >= 0; x--) {
        for (let y = 1; y <= n; y++) {
            if (x + 2 * y >= n) {
                dp[x][y] = suffixSum[x];
            } else {
                for (let j = 1; j <= 2 * y; j++) {
                    dp[x][y] = Math.max(
                        dp[x][y],
                        suffixSum[x] -
                        dp[x + j][Math.max(y, j)]
                    );
                }
            }
        }
    }

    return dp[0][1];
};