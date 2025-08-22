/**
3195. Find the Minimum Area to Cover All Ones I
    You are given a 2D binary array grid. Find a rectangle with horizontal and vertical sides with the smallest area, such that all the 1's in grid lie inside this rectangle.
    Return the minimum possible area of the rectangle.

    Example :

    Input: grid = [[0,1,0],[1,0,1]]
    Output: 6
    Explanation:
    The smallest rectangle has a height of 2 and a width of 3, so it has an area of 2 * 3 = 6.
 */



function minimumArea(grid: number[][]): number {
    const row = grid.length, col = grid[0].length;
    let minRow = Infinity, minCol = Infinity;
    let maxRow = -Infinity, maxCol = -Infinity;
    for (let i = 0; i < row; i++){
        for (let j = 0; j < col; j++){
            if (grid[i][j] == 1){
                minRow = Math.min(minRow, i);
                maxRow = Math.max(maxRow, i);
                minCol = Math.min(minCol, j);
                maxCol = Math.max(maxCol, j);
            }
        }
    }
    return (maxRow - minRow + 1) * (maxCol - minCol + 1);
};