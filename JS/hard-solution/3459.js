/**
3459. Length of Longest V-Shaped Diagonal Segment
    You are given a 2D integer matrix grid of size n x m, where each element is either 0, 1, or 2.
    A V-shaped diagonal segment is defined as:
    The segment starts with 1.
    The subsequent elements follow this infinite sequence: 2, 0, 2, 0, ....
    The segment:
    Starts along a diagonal direction (top-left to bottom-right, bottom-right to top-left, top-right to bottom-left, or bottom-left to top-right).
    Continues the sequence in the same diagonal direction.
    Makes at most one clockwise 90-degree turn to another diagonal direction while maintaining the sequence.

    Return the length of the longest V-shaped diagonal segment. If no valid segment exists, return 0.

    Example :
    Input: grid = [[2,2,1,2,2],[2,0,2,2,0],[2,0,1,1,0],[1,0,2,2,2],[2,0,0,2,2]]
    Output: 5
    Explanation:
    The longest V-shaped diagonal segment has a length of 5 and follows these coordinates: (0,2) → (1,3) → (2,4), takes a 90-degree clockwise turn at (2,4), and continues as (3,3) → (4,2).
 */


/**
 * @param {number[][]} grid
 * @return {number}
 */
var lenOfVDiagonal = function(grid) {
    const n = grid.length;
    const m = grid[0].length;

    const DIRS = [[1,1],[1,-1],[-1,-1],[-1,1]];

    const memo = Array.from({length: n}, () => Array.from({length: m}, () => Array(8).fill(0)));

    let ans = 0;


    for(let i = 0; i < n; i++) {
        for(let j = 0; j < m; j++) {
            if(grid[i][j] !== 1) continue; 
            const maxs = [n - i, j + 1, i + 1, m - j];

            for(let k = 0; k < 4; k++) {
                if(maxs[k] > ans) {
                
                    ans = Math.max(ans, dfs(i, j, k, 1, 2) + 1);
                }
            }
        }
    }
    return ans;
    function dfs(i, j, k, canTurn, target) {
        i += DIRS[k][0];
        j += DIRS[k][1];
        if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] !== target) {
            return 0;
        }
        const mask = (k << 1) | canTurn;
        if(memo[i][j][mask] > 0) return memo[i][j][mask];
        let res = dfs(i, j, k, canTurn, 2 - target);
        if(canTurn === 1) {
            const maxs = [n - i - 1, j, i, m - j - 1];
            const nk = (k + 1) % 4;
            if(maxs[nk] > res) {
                res = Math.max(res, dfs(i, j, nk, 0, 2 - target));
            }
        }

        return memo[i][j][mask] = res + 1;
    }
};