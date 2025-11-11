/**
474. Ones and Zeroes
    You are given an array of binary strings strs and two integers m and n.
    Return the size of the largest subset of strs such that there are at most m 0's and n 1's in the subset.
    A set x is a subset of a set y if all elements of x are also elements of y.

    Example :
    Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3
    Output: 4
    Explanation: The largest subset with at most 5 0's and 3 1's is {"10", "0001", "1", "0"}, so the answer is 4.
    Other valid but smaller subsets include {"0001", "1"} and {"10", "1", "0"}.
    {"111001"} is an invalid subset because it contains 4 1's, greater than the maximum of 3.
 */



function findMaxForm(strs: string[], m: number, n: number): number {
    const dp : number[][] = Array.from({length : m + 1}, () => Array(n + 1).fill(0));
    for (let s of strs){
        let count0 = 0, count1 = 0;
        for (let c of s){
            if (c === '0')
                count0++;
            else 
                count1++;
        }
        for (let i = m; i >= count0; i--){
            for (let j = n; j >= count1; j--){
                dp[i][j] = Math.max(dp[i][j], dp[i - count0][j - count1] + 1);
            }
        }
    }
    return dp[m][n];
};