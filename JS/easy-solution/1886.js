/*
1886. Determine Whether Matrix Can Be Obtained By Rotation
    Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.
    
    Example :
    Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
    Output: true
    Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
*/


/**
 * @param {number[][]} mat
 * @param {number[][]} target
 * @return {boolean}
 */
var findRotation = function(mat, target) {
    const n = mat.length;

    const isEqual = () => {
        for (let i = 0; i < n; i++)
            for (let j = 0; j < n; j++)
                if (mat[i][j] !== target[i][j])
                    return false;
        return true;
    };

    for (let r = 0; r < 4; r++) {

        for (let i = 0; i < Math.floor(n / 2); i++) {
            for (let j = 0; j < Math.floor((n + 1) / 2); j++) {

                const temp = mat[i][j];

                mat[i][j] = mat[n - 1 - j][i];
                mat[n - 1 - j][i] = mat[n - 1 - i][n - 1 - j];
                mat[n - 1 - i][n - 1 - j] = mat[j][n - 1 - i];
                mat[j][n - 1 - i] = temp;
            }
        }

        if (isEqual())
            return true;
    }

    return false;
};