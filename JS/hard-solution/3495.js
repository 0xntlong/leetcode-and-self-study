/**
3495. Minimum Operations to Make Array Elements Zero 
    You are given a 2D array queries, where queries[i] is of the form [l, r]. Each queries[i] defines an array of integers nums consisting of elements ranging from l to r, both inclusive.
    In one operation, you can:
    Select two integers a and b from the array.
    Replace them with floor(a / 4) and floor(b / 4).
    Your task is to determine the minimum number of operations required to reduce all elements of the array to zero for each query. Return the sum of the results for all queries.

    Example :
    Input: queries = [[1,2],[2,4]]
    Output: 3
    Explanation:
    For queries[0]:
    The initial array is nums = [1, 2].
    In the first operation, select nums[0] and nums[1]. The array becomes [0, 0].
    The minimum number of operations required is 1.
    For queries[1]:

    The initial array is nums = [2, 3, 4].
    In the first operation, select nums[0] and nums[2]. The array becomes [0, 3, 1].
    In the second operation, select nums[1] and nums[2]. The array becomes [0, 0, 0].
    The minimum number of operations required is 2.
    The output is 1 + 2 = 3.
 */




/**
 * @param {number[][]} queries
 * @return {number}
 */
var minOperations = function(queries) {
    const pow4 = [1n];
    while (pow4[pow4.length - 1] <= 1000000000n) {
        pow4.push(pow4[pow4.length - 1] * 4n);
    }

    const prefix = [0n];
    for (let i = 0; i < pow4.length - 1; i++) {
        prefix.push(prefix[prefix.length - 1] + BigInt(i + 1) * 3n * pow4[i]);
    }

    function F(n) {
        if (n <= 0n) return 0n;
        let idx = upperBound(pow4, n) - 1;
        return prefix[idx] + BigInt(idx + 1) * (n - pow4[idx] + 1n);
    }

    function upperBound(arr, x) {
        let l = 0, r = arr.length;
        while (l < r) {
        let m = (l + r) >> 1;
        if (arr[m] <= x) l = m + 1;
        else r = m;
        }
        return l;
    }

    let res = 0n;
    for (let [l, r] of queries) {
        let s = F(BigInt(r)) - F(BigInt(l - 1));
        res += (s + 1n) / 2n;
    }
    return Number(res);
};