/**
2643. Row with Maximum Ones
    Given a m x n binary matrix mat, find the 0-indexed position of the row that contains the maximum count of ones, and the number of ones in that row.
    In case there are multiple rows that have the maximum count of ones, the row with the smallest row number should be selected.
    Return an array containing the index of the row, and the number of ones in it.

    Example :
    Input: mat = [[0,1],[1,0]]
    Output: [0,1]
    Explanation: Both rows have the same number of 1's. So we return the index of the smaller row, 0, and the maximum count of ones (1). So, the answer is [0,1]. 
 */

/**
 * @param {number[][]} mat
 * @return {number[]}
 */
var rowAndMaximumOnes = function(mat) {
    let res = [0, 0];
    let row = mat.length;
    for (let i = 0; i < row; i++){
        let count = mat[i].reduce((acc, val) => acc + val, 0);
        if (count > res[1]){
            res[0] = i;
            res[1] = count;
        }
    }
    return res;
};