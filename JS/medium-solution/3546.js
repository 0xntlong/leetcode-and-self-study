/**
3546. Equal Sum Grid Partition I
    You are given an m x n matrix grid of positive integers. Your task is to determine if it is possible to make either one horizontal or one vertical cut on the grid such that:
    Each of the two resulting sections formed by the cut is non-empty.
    The sum of the elements in both sections is equal.
    Return true if such a partition exists; otherwise return false.

    Example :
    Input: grid = [[1,4],[2,3]]

    Output: true
    Explanation:
    A horizontal cut between row 0 and row 1 results in two non-empty sections, each with a sum of 5. Thus, the answer is true.
 */



/**
 * @param {number[][]} grid
 * @return {boolean}
 */
var canPartitionGrid = function(grid) {
    let m = grid.length;
    let n = grid[0].length;

    let total = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            total += grid[i][j];
        }
    }

    if (total % 2 !== 0) {
        return false;
    }

    let target = total / 2;
    let curr = 0;
    
    for (let i = 0; i < m - 1; i++) {
        for (let j = 0; j < n; j++) {
            curr += grid[i][j];
        }
        if (curr === target) {
            return true;
        }
    }

    curr = 0;
    for (let j = 0; j < n - 1; j++) {
        for (let i = 0; i < m; i++) {
            curr += grid[i][j];
        }
        if (curr === target) {
            return true;
        }
    }

    return false;
};