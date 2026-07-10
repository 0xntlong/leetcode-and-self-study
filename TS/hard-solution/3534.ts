/**
3534. Path Existence Queries in a Graph II
    You are given an integer n representing the number of nodes in a graph, labeled from 0 to n - 1.
    You are also given an integer array nums of length n and an integer maxDiff.
    An undirected edge exists between nodes i and j if the absolute difference between nums[i] and nums[j] is at most maxDiff (i.e., |nums[i] - nums[j]| <= maxDiff).
    You are also given a 2D integer array queries. For each queries[i] = [ui, vi], find the minimum distance between nodes ui and vi. If no path exists between the two nodes, return -1 for that query.
    Return an array answer, where answer[i] is the result of the ith query.
    Note: The edges between the nodes are unweighted.

    Example:
    Input: n = 5, nums = [1,8,3,4,2], maxDiff = 3, queries = [[0,3],[2,4]]
    Output: [1,1]
    Explanation:
    The resulting graph is:

    Query	Shortest Path	Minimum Distance
    [0, 3]	0 → 3	1
    [2, 4]	2 → 4	1
    Thus, the output is [1, 1].
 */



function pathExistenceQueries(n: number, nums: number[], maxDiff: number, queries: number[][]): number[] {
    const LOG = 18;
    const vec: number[][] = [];
    for (let i = 0; i < n; i++) {
        vec.push([nums[i], i]);
    }
    vec.sort((a, b) => {
        if (a[0] !== b[0]) 
            return a[0] - b[0];
        return a[1] - b[1];
    });
    const getSortIdx: number[] = new Array(n);
    for (let i = 0; i < n; i++) {
        getSortIdx[vec[i][1]] = i;
    }
    const st: number[][] = Array.from({ length: n }, () => new Array(LOG).fill(0));
    let l = 0;
    for (let r = 0; r < n; r++) {
        while (vec[r][0] - vec[l][0] > maxDiff) {
            st[l][0] = r - 1;
            l++;
        }
    }
    while (l < n) {
        st[l][0] = n - 1;
        l++;
    }
    for (let j = 1; j < LOG; j++) {
        for (let i = 0; i < n; i++) {
            st[i][j] = st[st[i][j - 1]][j - 1];
        }
    }
    const ans: number[] = new Array(queries.length).fill(-1);
    for (let i = 0; i < queries.length; i++) {
        let a = getSortIdx[queries[i][0]];
        let b = getSortIdx[queries[i][1]];
        if (a > b) {
            [a, b] = [b, a];
        }
        if (a === b) {
            ans[i] = 0;
            continue;
        }
        let cur = a;
        let step = 0;

        for (let j = LOG - 1; j >= 0; j--) {
            if (st[cur][j] < b) {
                step += 1 << j;
                cur = st[cur][j];
            }
        }
        if (st[cur][0] >= b) {
            ans[i] = step + 1;
        }
    }
    return ans;
};