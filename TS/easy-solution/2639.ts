/**
2639. Find the Width of the Columns in a Grid
    You are given a 0-indexed m x n integer matrix grid. The width of a column is the maximum length of its integers.
    For example, if grid = [[-10], [3], [12]], the width of the only column is 3 since -10 is of length 3.
    Return an integer array ans of size n where ans[i] is the width of the ith column.
    The length of an integer x with len digits is equal to len if x is non-negative, and len + 1 otherwise.

    Example :
    Input: grid = [[1],[22],[333]]
    Output: [3]
    Explanation: In the 0th column, 333 is of length 3.
 */

    function findColumnWidth(grid: number[][]): number[] {
        const col = grid[0].length;
        const res : number[] = [];
        for (let i = 0; i < col; i++){
            let maxi = 0;
            for (let row of grid){
                maxi = Math.max(maxi, row[i].toString().length);
            }
            res.push(maxi);
        }
        return res;
    };