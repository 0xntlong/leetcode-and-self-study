/**
2438. Range Product Queries of Powers
    Given a positive integer n, there exists a 0-indexed array called powers, composed of the minimum number of powers of 2 that sum to n. The array is sorted in non-decreasing order, and there is only one way to form the array.
    You are also given a 0-indexed 2D integer array queries, where queries[i] = [lefti, righti]. Each queries[i] represents a query where you have to find the product of all powers[j] with lefti <= j <= righti.
    Return an array answers, equal in length to queries, where answers[i] is the answer to the ith query. Since the answer to the ith query may be too large, each answers[i] should be returned modulo 109 + 7.

    Example :
    Input: n = 15, queries = [[0,1],[2,2],[0,3]]
    Output: [2,4,64]
    Explanation:
    For n = 15, powers = [1,2,4,8]. It can be shown that powers cannot be a smaller size.
    Answer to 1st query: powers[0] * powers[1] = 1 * 2 = 2.
    Answer to 2nd query: powers[2] = 4.
    Answer to 3rd query: powers[0] * powers[1] * powers[2] * powers[3] = 1 * 2 * 4 * 8 = 64.
    Each answer modulo 109 + 7 yields the same answer, so [2,4,64] is returned.
 */




/**
 * @param {number} n
 * @param {number[][]} queries
 * @return {number[]}
 */
var productQueries = function(n, queries) {
    const mod = 1000000007n;
    let power = 1;
    while (power <= n)
        power <<= 1;
    power >>= 1;
    const parts = [];
    let m = n;
    while (m > 0){
        if (power <= m){
            parts.push(BigInt(power));
            m -= power;
        }
        power >>= 1;
    }
    const k = parts.length;
    const prefix = Array.from({length : k}, () => Array(k).fill(0n));
    for (let i = 0; i < k; i++){
        prefix[i][i] = parts[k - 1 - i] % mod;
        for (let j = i + 1; j < k; j++){
            prefix[i][j] = (prefix[i][j - 1] * parts[k - 1 - j]) % mod;
        }
    }
    const res = new Array(queries.length);
    for (let i = 0; i < queries.length; i++){
        const [l, r]= queries[i];
        res[i] = Number(prefix[l][r]);
    }
    return res;
};