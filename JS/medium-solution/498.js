/**
498. Diagonal Traverse
    Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

    Example 1:
    Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
    Output: [1,2,4,7,5,3,6,8,9]
*/


/**
 * @param {number[][]} mat
 * @return {number[]}
 */
var findDiagonalOrder = function(mat) {
    const m = mat.length, n = mat[0].length;
    const res = new Array(m * n);
    let i = 0, j = 0, dir = 1, idx = 0;
    for (let cnt = 0; cnt < m * n; cnt++){
        res[idx++] = mat[i][j];
        if (dir == 1){
            if (j === n - 1){
                i++;
                dir = -1;
            } else if (i === 0){
                j++;
                dir = -1;
            } else {
                i--;
                j++;
            }
        } else {
            if (i === m - 1){
                j++;
                dir = 1;
            } else if ( j === 0){
                i++;
                dir = 1;
            } else {
                i++;
                j--;
            }
        }
    }
    return res;
};