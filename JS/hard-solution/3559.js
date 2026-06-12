/**
3559. Number of Ways to Assign Edge Weights II
    There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.
    Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.
    The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.
    You are given a 2D integer array queries. For each queries[i] = [ui, vi], determine the number of ways to assign weights to edges in the path such that the cost of the path between ui and vi is odd.
    Return an array answer, where answer[i] is the number of valid assignments for queries[i].
    Since the answer may be large, apply modulo 109 + 7 to each answer[i].
    Note: For each query, disregard all edges not in the path between node ui and vi.

    Example :

    Input: edges = [[1,2]], queries = [[1,1],[1,2]]
    Output: [0,1]
    Explanation:
    Query [1,1]: The path from Node 1 to itself consists of no edges, so the cost is 0. Thus, the number of valid assignments is 0.
    Query [1,2]: The path from Node 1 to Node 2 consists of one edge (1 → 2). Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
 */



/**
 * @param {number[][]} edges
 * @param {number[][]} queries
 * @return {number[]}
 */
var assignEdgeWeights = function(edges, queries) {
    const MOD = 1000000007;
    const n = edges.length + 1;
    const adj = Array.from({ length: n + 1 }, () => []);
    for (const [u, v] of edges) {
        adj[u].push(v);
        adj[v].push(u);
    }

    const depth = Array(n + 1).fill(0);
    const parent = Array(n + 1).fill(0);
    const visited = Array(n + 1).fill(false);
    const q = [1];
    visited[1] = true;
    for (let head = 0; head < q.length; head++) {
        const node = q[head];
        for (const nei of adj[node]) {
            if (!visited[nei]) {
                visited[nei] = true;
                depth[nei] = depth[node] + 1;
                parent[nei] = node;
                q.push(nei);
            }
        }
    }

    let LOG = 1;
    while ((1 << LOG) <= n) 
        LOG++;
    const up = Array.from({ length: LOG }, () => Array(n + 1).fill(0));
    up[0] = [...parent];
    for (let k = 1; k < LOG; k++) {
        for (let v = 0; v <= n; v++) {
            up[k][v] = up[k - 1][up[k - 1][v]];
        }
    }
    const lca = (u, v) => {
        if (depth[u] < depth[v]) {
            [u, v] = [v, u];
        }
        let diff = depth[u] - depth[v];
        for (let k = 0; k < LOG; k++) {
            if ((diff >> k) & 1) {
                u = up[k][u];
            }
        }
        if (u === v) 
            return u;
        for (let k = LOG - 1; k >= 0; k--) {
            if (up[k][u] !== up[k][v]) {
                u = up[k][u];
                v = up[k][v];
            }
        }
        return up[0][u];
    };
    const pow2 = Array(n + 1).fill(1);
    for (let i = 1; i <= n; i++) {
        pow2[i] = (pow2[i - 1] * 2) % MOD;
    }
    const ans = [];
    for (const [u, v] of queries) {
        const ancestor = lca(u, v);
        const dist = depth[u] + depth[v] - 2 * depth[ancestor];
        ans.push(dist === 0 ? 0 : pow2[dist - 1]);
    }
    return ans;
};