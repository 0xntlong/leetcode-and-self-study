/*
1351. Count Negative Numbers in a Sorted Matrix
    Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, return the number of negative numbers in grid.

    Example:
    Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
    Output: 8
    Explanation: There are 8 negatives number in the matrix.
*/



function countNegatives(grid: number[][]): number {
    const countRow = (row: number[]) : number => {
        let l = 0, r = row.length;
        while (l < r){
            const mid = Math.floor(l + (r - l) / 2);
            if (row[mid] < 0)
                r = mid;
            else
                l = mid + 1;
        }
        return row.length - l;
    };
    let count = 0;
    for (const row of grid){
        count += countRow(row);
    }
    return count;
};