/**
1559. Detect Cycles in 2D Grid
    Given a 2D array of characters grid of size m x n, you need to find if there exists any cycle consisting of the same value in grid.
    A cycle is a path of length 4 or more in the grid that starts and ends at the same cell. From a given cell, you can move to one of the cells adjacent to it - in one of the four directions (up, down, left, or right), if it has the same value of the current cell.
    Also, you cannot move to the cell that you visited in your last move. For example, the cycle (1, 1) -> (1, 2) -> (1, 1) is invalid because from (1, 2) we visited (1, 1) which was the last visited cell.
    Return true if any cycle of the same value exists in grid, otherwise, return false.


    Example 1:
    Input: grid = [["a","a","a","a"],["a","b","b","a"],["a","b","b","a"],["a","a","a","a"]]
    Output: true
    Explanation: There are two valid cycles shown in different colors in the image below:
 */


/**
 * @param {character[][]} grid
 * @return {boolean}
 */
var containsCycle = function(grid) {
    const rows = grid.length, cols = grid[0].length;
    const parent = Array.from({ length: rows * cols }, (_, i) => i);
    function find(x) {
        while (parent[x] !== x) {
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }

    function unionSets(a, b) {
        const ra = find(a), rb = find(b);
        if (ra === rb) 
            return true;
        parent[ra] = rb;
        return false;
    }

    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (j + 1 < cols && grid[i][j] === grid[i][j + 1]) {
                if (unionSets(i * cols + j, i * cols + j + 1)) 
                    return true;

            }
            if (i + 1 < rows && grid[i][j] === grid[i + 1][j]) {
                if (unionSets(i * cols + j, (i + 1) * cols + j)) 
                    return true;
            }
        }
    }
    return false;
};