/**
1411. Number of Ways to Paint N x 3 Grid
    You have a grid of size n x 3 and you want to paint each cell of the grid with exactly one of the three colors: Red, Yellow, or Green while making sure that no two adjacent cells have the same color (i.e., no two cells that share vertical or horizontal sides have the same color).
    Given n the number of rows of the grid, return the number of ways you can paint this grid. As the answer may grow large, the answer must be computed modulo 109 + 7.

    Example :
    Input: n = 1
    Output: 12
    Explanation: There are 12 possible way to paint the grid as shown.
 */



function numOfWays(n: number): number {
    const MOD = 1_000_000_007;
    let count2 = 6, count3 = 6;

    for (let i = 1; i < n; i++) {
        const new2 = (3 * count2 + 2 * count3) % MOD;
        const new3 = (2 * count2 + 2 * count3) % MOD;
        count2 = new2;
        count3 = new3;
    }
    return (count2 + count3) % MOD;
};