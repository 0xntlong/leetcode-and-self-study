/*
1582. Special Positions in a Binary Matrix
    Given an m x n binary matrix mat, return the number of special positions in mat.
    A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

    Example :
    Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
    Output: 1
    Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
*/


function numSpecial(mat: number[][]): number {
    const m = mat.length, n = mat[0].length;

    const getColSum = (col: number): number => {
        let s = 0;
        for (let r = 0; r < m; r++) 
            s += mat[r][col];
        return s;
    };

    let special = 0;

    for (let r = 0; r < m; r++) {
        let rowSum = 0;
        let col = -1;

        for (let c = 0; c < n; c++) {
            rowSum += mat[r][c];
            if (mat[r][c] === 1) 
                col = c;
        }

        if (rowSum === 1 && getColSum(col) === 1) 
            special++;
    }

    return special;
};