/**
2322. Minimum Score After Removals on a Tree
    There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.
    You are given a 0-indexed integer array nums of length n where nums[i] represents the value of the ith node. You are also given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.
    Remove two distinct edges of the tree to form three connected components. For a pair of removed edges, the following steps are defined:
    Get the XOR of all the values of the nodes for each of the three components respectively.
    The difference between the largest XOR value and the smallest XOR value is the score of the pair.
    For example, say the three components have the node values: [4,5,7], [1,9], and [3,3,3]. The three XOR values are 4 ^ 5 ^ 7 = 6, 1 ^ 9 = 8, and 3 ^ 3 ^ 3 = 3. The largest XOR value is 8 and the smallest XOR value is 3. The score is then 8 - 3 = 5.
    Return the minimum score of any possible pair of edge removals on the given tree.

    Example :
    Input: nums = [1,5,5,4,11], edges = [[0,1],[1,2],[1,3],[3,4]]
    Output: 9
    Explanation: The diagram above shows a way to make a pair of removals.
    - The 1st component has nodes [1,3,4] with values [5,4,11]. Its XOR value is 5 ^ 4 ^ 11 = 10.
    - The 2nd component has node [0] with value [1]. Its XOR value is 1 = 1.
    - The 3rd component has node [2] with value [5]. Its XOR value is 5 = 5.
    The score is the difference between the largest and smallest XOR value which is 10 - 1 = 9.
    It can be shown that no other pair of removals will obtain a smaller score than 9.
 */



/**
 * @param {number[]} nums
 * @param {number[][]} edges
 * @return {number}
 */
var minimumScore = function(nums, edges) {
    const n = nums.length;
    const graph = Array.from({ length: n }, () => []);
    for (const [u, v] of edges){
        graph[u].push(v);
        graph[v].push(u);
    }
    const xorSubTree = Array(n).fill(0);
    const inTime = Array(n).fill(0);
    const outTime = Array(n).fill(0);
    let time = 0;
    const DFS = (u, parent) => {
        let xor = nums[u];
        inTime[u] = time++;
        for (const v of graph[u]){
            if (v !== parent){
                xor ^= DFS(v, u);
            }
        }
        outTime[u] = time;
        xorSubTree[u] = xor;
        return xor;
    };
    const find = (u, v) => {
        return inTime[u] < inTime[v] && outTime[v] <= outTime[u];
    };
    const totalXor = DFS(0, -1);
    const subTreeRoots = [];
    for (const [u, v] of edges){
        subTreeRoots.push(inTime[u] > inTime[v] ? u : v);
    }
    let minScore = Infinity;
    const m = subTreeRoots.length;
    for (let i = 0; i < m; i++){
        for (let j = i + 1; j < m; j++){
            const u  = subTreeRoots[i];
            const v = subTreeRoots[j];
            let a, b, c;
            if (find(u, v)){
                a = xorSubTree[v];
                b = xorSubTree[u] ^ xorSubTree[v];
                c = totalXor ^ xorSubTree[u];
            } else if (find(v, u)){
                a = xorSubTree[u];
                b = xorSubTree[v] ^ xorSubTree[u];
                c = totalXor ^ xorSubTree[v];
            } else {
                a = xorSubTree[u];
                b = xorSubTree[v];
                c = totalXor ^ xorSubTree[u] ^ xorSubTree[v];
            }
            const score = Math.max(a, b, c) - Math.min(a, b, c);
            minScore = Math.min(minScore, score);
        }
    }
    return minScore;
};