/**
118. Pascal's Triangle
    Given an integer numRows, return the first numRows of Pascal's triangle.

    In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

    Example :
    Input: numRows = 5
    Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
*/


function generate(numRows: number): number[][] {
    const temp: number[][] = [];
    for (let i = 0; i < numRows; i++){
        temp[i] = new Array(i + 1).fill(1);
        for (let j = 1; j <= Math.floor(i / 2); j++){
            const val = temp[i - 1][j - 1] + temp[i - 1][j];
            temp[i][j] = temp[i][i - j] = val;
        }
    }
    return temp;
};