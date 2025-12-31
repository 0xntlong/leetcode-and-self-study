/**
1970. Last Day Where You Can Still Cross
    There is a 1-based binary matrix where 0 represents land and 1 represents water. You are given integers row and col representing the number of rows and columns in the matrix, respectively.
    Initially on day 0, the entire matrix is land. However, each day a new cell becomes flooded with water. You are given a 1-based 2D array cells, where cells[i] = [ri, ci] represents that on the ith day, the cell on the rith row and cith column (1-based coordinates) will be covered with water (i.e., changed to 1).
    You want to find the last day that it is possible to walk from the top to the bottom by only walking on land cells. You can start from any cell in the top row and end at any cell in the bottom row. You can only travel in the four cardinal directions (left, right, up, and down).
    Return the last day where it is possible to walk from the top to the bottom by only walking on land cells.

    Example :
    Input: row = 2, col = 2, cells = [[1,1],[2,1],[1,2],[2,2]]
    Output: 2
    Explanation: The above image depicts how the matrix changes each day starting from day 0.
    The last day where it is possible to cross from top to bottom is on day 2.
 */


/**
 * @param {number} row
 * @param {number} col
 * @param {number[][]} cells
 * @return {number}
 */
var latestDayToCross = function(row, col, cells) {
    const dx = [1, -1, 0, 0];
    const dy = [0, 0, 1, -1];

    const canCross = (n) => {
        const grid = Array.from({ length: row }, () => Array(col).fill(0));
        for (let i = 0; i < n; i++) {
            const [r, c] = cells[i];
            grid[r - 1][c - 1] = 1;
        }

        const queue = [];
        for (let c = 0; c < col; c++) {
            if (grid[0][c] === 0) {
                queue.push([0, c]);
                grid[0][c] = 1;
            }
        }

        while (queue.length) {
            const [x, y] = queue.shift();
            if (x === row - 1) return true;

            for (let k = 0; k < 4; k++) {
                const nx = x + dx[k], ny = y + dy[k];
                if (nx >= 0 && nx < row && ny >= 0 && ny < col && grid[nx][ny] === 0) {
                    grid[nx][ny] = 1;
                    queue.push([nx, ny]);
                }
            }
        }
        return false;
    };

    let left = 0, right = row * col;
    while (right - left > 1) {
        const mid = (left + right) >> 1;
        if (canCross(mid)) left = mid;
        else right = mid;
    }
    return left;
};