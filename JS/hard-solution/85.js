/**
85. Maximal Rectangle
    Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.

    Example :
    Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
    Output: 6
    Explanation: The maximal rectangle is shown in the above picture.
*/



/**
 * @param {character[][]} matrix
 * @return {number}
 */
var maximalRectangle = function(matrix) {
    const row = matrix.length;
    if (row === 0) return 0;
    const col = matrix[0].length;
    if (col === 0) return 0;

    const calculate = (h) => {
        const st = []; // [height, start]
        let maxArea = 0;
        const n = h.length;

        for (let i = 0; i < n; i++) {
            let start = i;
            while (st.length && st[st.length - 1][0] > h[i]) {
                const [val, idx] = st.pop();
                maxArea = Math.max(maxArea, val * (i - idx));
                start = idx;
            }
            st.push([h[i], start]);
        }

        while (st.length) {
            const [val, idx] = st.pop();
            maxArea = Math.max(maxArea, val * (n - idx));
        }
        return maxArea;
    };

    const heights = new Array(col).fill(0);
    let ans = 0;

    for (let i = 0; i < row; i++) {
        for (let j = 0; j < col; j++) {
            if (matrix[i][j] === '1') heights[j] += 1;
            else heights[j] = 0;
        }
        ans = Math.max(ans, calculate(heights));
    }

    return ans;
};