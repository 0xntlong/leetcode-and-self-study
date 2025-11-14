/**
2536. Increment Submatrices by One
    You are given a positive integer n, indicating that we initially have an n x n 0-indexed integer matrix mat filled with zeroes.
    You are also given a 2D integer array query. For each query[i] = [row1i, col1i, row2i, col2i], you should do the following operation:
    Add 1 to every element in the submatrix with the top left corner (row1i, col1i) and the bottom right corner (row2i, col2i). That is, add 1 to mat[x][y] for all row1i <= x <= row2i and col1i <= y <= col2i.
    Return the matrix mat after performing every query.

    Example :
    Input: n = 3, queries = [[1,1,2,2],[0,0,1,1]]
    Output: [[1,1,0],[1,2,1],[0,1,1]]
    Explanation: The diagram above shows the initial matrix, the matrix after the first query, and the matrix after the second query.
    - In the first query, we add 1 to every element in the submatrix with the top left corner (1, 1) and bottom right corner (2, 2).
    - In the second query, we add 1 to every element in the submatrix with the top left corner (0, 0) and bottom right corner (1, 1).
 */



function rangeAddQueries(n: number, queries: number[][]): number[][] {
    const res: number[][] = Array.from({ length: n }, () => Array(n).fill(0));
    for (const q of queries) {
        let [r1, c1, r2, c2] = q;
        r2++;
        c2++;
        res[r1][c1] += 1;
        if (c2 < n) 
            res[r1][c2] -= 1;
        if (r2 < n) {
            res[r2][c1] -= 1;
            if (c2 < n) 
                res[r2][c2] += 1;
        }
    }
    const dp: number[] = Array(n).fill(0);
    for (let i = 0; i < n; i++) {
        let acc = 0;
        for (let j = 0; j < n; j++) {
            dp[j] += res[i][j];
            acc += dp[j];
            res[i][j] = acc;
        }
    }
    return res;
};