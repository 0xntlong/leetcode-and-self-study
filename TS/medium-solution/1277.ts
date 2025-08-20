/*
1277. Count Square Submatrices with All Ones
    Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

    Example :
    Input: matrix =
    [
    [0,1,1,1],
    [1,1,1,1],
    [0,1,1,1]
    ]
    Output: 15
    Explanation: 
    There are 10 squares of side 1.
    There are 4 squares of side 2.
    There is  1 square of side 3.
    Total number of squares = 10 + 4 + 1 = 15.
*/




function countSquares(matrix: number[][]): number {
    let rows = matrix.length;
    let cols = matrix[0].length;
    let dp: number[][] = Array.from({ length : rows }, () => Array(cols).fill(0));
    let cnt = 0;
    for (let j = 0; j < cols; j++){
        if (matrix[0][j] === 1){
            dp[0][j] = 1;
            cnt += dp[0][j];
        }
    }
    for (let i = 1; i < rows; i++){
        if (matrix[i][0] === 1){
            dp[i][0] = 1;
            cnt += dp[i][0];
        }
    }
    for (let i = 1; i < rows; i++){
        for (let j = 1; j < cols; j++){
            if (matrix[i][j] === 1){
                dp[i][j] = Math.min(dp[i-1][j], Math.min(dp[i-1][j-1], dp[i][j-1])) + 1;
                cnt += dp[i][j];
            }
        }
    }
    return cnt;
};