/**
1727. Largest Submatrix With Rearrangements
    You are given a binary matrix matrix of size m x n, and you are allowed to rearrange the columns of the matrix in any order.
    Return the area of the largest submatrix within matrix where every element of the submatrix is 1 after reordering the columns optimally.

    Example :
    Input: matrix = [[0,0,1],[1,1,1],[1,0,1]]
    Output: 4
    Explanation: You can rearrange the columns as shown above.
    The largest submatrix of 1s, in bold, has an area of 4.
 */


/**
 * @param {number[][]} matrix
 * @return {number}
 */
var largestSubmatrix = function(matrix) {
    if (!matrix.length) 
        return 0;

    const m = matrix.length;
    const n = matrix[0].length;
    const heights = new Array(n).fill(0);
    let maxArea = 0;

    for (const row of matrix) {

        for (let j = 0; j < n; j++)
            heights[j] = row[j] ? heights[j] + 1 : 0;

        const sortedH = [...heights].sort((a, b) => b - a);

        for (let j = 0; j < n; j++)
            maxArea = Math.max(maxArea, sortedH[j] * (j + 1));
    }

    return maxArea;
};