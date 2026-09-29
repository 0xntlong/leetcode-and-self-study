/**
2267. Check if There Is a Valid Parentheses String Path
    A parentheses string is a non-empty string consisting only of '(' and ')'. It is valid if any of the following conditions is true:
    It is ().
    It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
    It can be written as (A), where A is a valid parentheses string.
    You are given an m x n matrix of parentheses grid. A valid parentheses string path in the grid is a path satisfying all of the following conditions:
    The path starts from the upper left cell (0, 0).
    The path ends at the bottom-right cell (m - 1, n - 1).
    The path only ever moves down or right.
    The resulting parentheses string formed by the path is valid.
    Return true if there exists a valid parentheses string path in the grid. Otherwise, return false.

    Example :
    Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
    Output: true
    Explanation: The above diagram shows two possible paths that form valid parentheses strings.
    The first path shown results in the valid parentheses string "()(())".
    The second path shown results in the valid parentheses string "((()))".
    Note that there may be other valid parentheses string paths.
 */



function hasValidPath(grid: string[][]): boolean {
    const m: number = grid.length;
    const n: number = grid[0].length;
    const lim: number = (m + n) >> 1;

    if (
        ((m + n) & 1) === 0 ||
        grid[0][0] === ")" ||
        grid[m - 1][n - 1] === "("
    ) {
        return false;
    }

    const maxMask: bigint = (1n << BigInt(lim + 1)) - 1n;
    const dp: bigint[] = new Array(n).fill(0n);

    dp[0] = 1n << 1n;

    let p: number = 1;

    for (let j = 1; j < n; j++) {
        p += grid[0][j] === "(" ? 1 : -1;

        if (p < 0 || p > lim) break;

        dp[j] = 1n << BigInt(p);
    }

    p = 1;

    for (let i = 1; i < m; i++) {
        p += grid[i][0] === "(" ? 1 : -1;

        if (dp[0] === 0n || p < 0 || p > lim)
            dp[0] = 0n;
        else
            dp[0] = 1n << BigInt(p);

        for (let j = 1; j < n; j++) {
            dp[j] = dp[j - 1] | dp[j];

            if (grid[i][j] === "(")
                dp[j] = (dp[j] << 1n) & maxMask;
            else
                dp[j] >>= 1n;
        }
    }

    return (dp[n - 1] & 1n) === 1n;
}