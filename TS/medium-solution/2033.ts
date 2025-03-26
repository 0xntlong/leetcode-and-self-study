/**
2033. Minimum Operations to Make a Uni-Value Grid
    You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.
    A uni-value grid is a grid where all the elements of it are equal.
    Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

    Example :
    Input: grid = [[2,4],[6,8]], x = 2
    Output: 4
    Explanation: We can make every element equal to 4 by doing the following: 
    - Add x to 2 once.
    - Subtract x from 6 once.
    - Subtract x from 8 twice.
    A total of 4 operations were used.
 */

    function minOperations(grid: number[][], x: number): number {
        let count: number[] = [];
        for (let row of grid) {
            for (let num of row) {
                count.push(num);
            }
        }
        count.sort((a, b) => a - b);
    
        for (let c of count) {
            if (Math.abs(c - count[0]) % x !== 0) {
                return -1; 
            }
        }
        let cost = count[Math.floor(count.length / 2)];
        let op = 0;
        for (let c of count) {
            op += Math.abs(c - cost) / x;
        }
    
        return op;
    }