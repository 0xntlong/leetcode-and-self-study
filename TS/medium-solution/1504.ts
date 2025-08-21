/**
1504. Count Submatrices With All Ones
    Given an m x n binary matrix mat, return the number of submatrices that have all ones.

    Example :
    Input: mat = [[1,0,1],[1,1,0],[1,1,0]]
    Output: 13
    Explanation: 
    There are 6 rectangles of side 1x1.
    There are 2 rectangles of side 1x2.
    There are 3 rectangles of side 2x1.
    There is 1 rectangle of side 2x2. 
    There is 1 rectangle of side 3x1.
    Total number of rectangles = 6 + 2 + 3 + 1 + 1 = 13.
 */



function numSubmat(mat: number[][]): number {
    const m = mat.length, n = mat[0].length;
    const height = Array(n).fill(0);
    let ans = 0;
    for (let i = 0; i < m; i++){
        for (let j = 0; j < n; j++){
            height[j] = mat[i][j] ? height[j] + 1 : 0;
        }
        const stack : [number, number][] = [];
        let cur = 0;
        for (const h of height){
            let cnt = 1;
            while (stack.length && stack[stack.length - 1][0] >= h){
                const [ph, pc] = stack.pop()!;
                cur -= ph * pc;
                cnt += pc;
            }
            cur += h * cnt;
            stack.push([h, cnt]);
            ans += cur;
        }
    }
    return ans;
};