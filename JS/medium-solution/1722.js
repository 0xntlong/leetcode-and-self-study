/**
1722. Minimize Hamming Distance After Swap Operations
    You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.
    The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).
    Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.

    Example :
    Input: source = [1,2,3,4], target = [2,1,4,5], allowedSwaps = [[0,1],[2,3]]
    Output: 1
    Explanation: source can be transformed the following way:
    - Swap indices 0 and 1: source = [2,1,3,4]
    - Swap indices 2 and 3: source = [2,1,4,3]
    The Hamming distance of source and target is 1 as they differ in 1 position: index 3.
 */


/**
 * @param {number[]} source
 * @param {number[]} target
 * @param {number[][]} allowedSwaps
 * @return {number}
 */
var minimumHammingDistance = function(source, target, allowedSwaps) {
    const n = source.length;
    const parent = Array.from({length: n}, (_, i) => i);
    const rank = Array(n).fill(0);
    const find = (x) => {
        if (parent[x] !== x) 
            parent[x] = find(parent[x]);
        return parent[x];

    };
    const uni = (a, b) => {
        let fa = find(a), fb = find(b);
        if (fa === fb) 
            return;

        if (rank[fa] < rank[fb]) 
            [fa, fb] = [fb, fa];
        parent[fb] = fa;

        if (rank[fa] === rank[fb]) 
            rank[fa]++;
    };
    for (let [a, b] of allowedSwaps) {
        uni(a, b);
    }

    const groups = new Map();
    for (let i = 0; i < n; i++) {
        const r = find(i);
        if (!groups.has(r)) 
            groups.set(r, []);

        groups.get(r).push(i);

    }

    let ans = 0;

    for (let idxs of groups.values()) {
        const freq = new Map();

        for (let i of idxs) {
            freq.set(source[i], (freq.get(source[i]) || 0) + 1);
        }

        for (let i of idxs) {
            if ((freq.get(target[i]) || 0) > 0) {
                freq.set(target[i], freq.get(target[i]) - 1);
            } else {
                ans++;
            }
        }
    }
    return ans;
};