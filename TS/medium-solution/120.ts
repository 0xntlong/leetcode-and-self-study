/**
120. Triangle
    Given a triangle array, return the minimum path sum from top to bottom.
    For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

    Example :
    Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
    Output: 11
    Explanation: The triangle looks like:
    2
    3 4
    6 5 7
    4 1 8 3
    The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11 (underlined above).
 */




function minimumTotal(triangle: number[][]): number {
    let n = triangle.length;
    let dp: number[] = new Array(n + 1).fill(0);
    for (let row = n - 1; row >= 0; row--){
        for (let i = 0; i < triangle[row].length; i++){
            dp[i] = Math.min(dp[i], dp[i + 1]) + triangle[row][i];
        }
    }
    return dp[0];
};