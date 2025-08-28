/**
3446. Sort Matrix by Diagonals
    You are given an n x n square matrix of integers grid. Return the matrix such that:
    The diagonals in the bottom-left triangle (including the middle diagonal) are sorted in non-increasing order.
    The diagonals in the top-right triangle are sorted in non-decreasing order.

    Example :
    Input: grid = [[1,7,3],[9,8,2],[4,5,6]]
    Output: [[8,2,3],[9,6,7],[4,5,1]]
    Explanation:
    The diagonals with a black arrow (bottom-left triangle) should be sorted in non-increasing order:
    [1, 8, 6] becomes [8, 6, 1].
    [9, 5] and [4] remain unchanged.
    The diagonals with a blue arrow (top-right triangle) should be sorted in non-decreasing order:
    [7, 2] becomes [2, 7].
    [3] remains unchanged.
 */




function sortMatrix(grid: number[][]): number[][] {
    const n = grid.length;
    for (let t = 0; t < n; t++){
        for (let i = 0; i < n - 1; i++){
            for (let j = 0; j < n - 1; j++){
                if (j > i){
                    if (grid[i][j] > grid[i + 1][j + 1]){
                        const tmp = grid[i][j];
                        grid[i][j] = grid[i + 1][j + 1];
                        grid[i + 1][j + 1] = tmp;
                    }
                } else {
                    if (grid[i][j] < grid[i + 1][j + 1]){
                        const tmp = grid[i][j];
                        grid[i][j] = grid[i + 1][j + 1];
                        grid[i + 1][j + 1] = tmp;
                    }
                }
            }
        }
    }
    return grid;
};