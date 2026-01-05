/*
1975. Maximum Matrix Sum
    You are given an n x n integer matrix. You can do the following operation any number of times:
    Choose any two adjacent elements of matrix and multiply each of them by -1.
    Two elements are considered adjacent if and only if they share a border.
    Your goal is to maximize the summation of the matrix's elements. Return the maximum sum of the matrix's elements using the operation mentioned above.

    Example :
    Input: matrix = [[1,-1],[-1,1]]
    Output: 4
    Explanation: We can follow the following steps to reach sum equals 4:
    - Multiply the 2 elements in the first row by -1.
    - Multiply the 2 elements in the first column by -1.
*/



function maxMatrixSum(matrix: number[][]): number {
    let total = 0;
    let cnt = 0;
    let mini = Number.POSITIVE_INFINITY;

    for (const row of matrix) {
        for (let x of row) {
            if (x < 0) {
                cnt++;
                x = -x;
            }
            if (x < mini) mini = x;
            total += x;
        }
    }

    return (cnt % 2 === 0) ? total : (total - 2 * mini);
};