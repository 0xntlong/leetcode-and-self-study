/**
1292. Maximum Side Length of a Square with Sum Less than or Equal to Threshold
Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.

    Example :
    Input: mat = [[1,1,3,2,4,3,2],[1,1,3,2,4,3,2],[1,1,3,2,4,3,2]], threshold = 4
    Output: 2
    Explanation: The maximum side length of square with sum less than 4 is 2 as shown.
 */



/**
 * @param {number[][]} mat
 * @param {number} threshold
 * @return {number}
 */
var maxSideLength = function(mat, threshold) {
     const m = mat.length, n = mat[0].length;
    const prefix = Array.from({ length: m + 1 }, () => Array(n + 1).fill(0));

    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            prefix[i + 1][j + 1] = mat[i][j] + prefix[i][j + 1] + prefix[i + 1][j] - prefix[i][j];
        }
    }

    let left = 1, right = Math.min(m, n), res = 0;

    while (left <= right) {
        const mid = (left + right) >> 1;
        let isValid = false;

        for (let i = mid; i <= m && !isValid; i++) {
            for (let j = mid; j <= n; j++) {
                const square_sum = prefix[i][j] - prefix[i - mid][j] - prefix[i][j - mid] + prefix[i - mid][j - mid];
                if (square_sum <= threshold) {
                    isValid = true;
                    break;
                }
            }
        }

        if (isValid) {
            res = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return res;
};