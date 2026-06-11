/**
3558. Number of Ways to Assign Edge Weights I
    There is an undirected tree with n nodes labeled from 1 to n, rooted at node 1. The tree is represented by a 2D integer array edges of length n - 1, where edges[i] = [ui, vi] indicates that there is an edge between nodes ui and vi.
    Initially, all edges have a weight of 0. You must assign each edge a weight of either 1 or 2.
    The cost of a path between any two nodes u and v is the total weight of all edges in the path connecting them.
    Select any one node x at the maximum depth. Return the number of ways to assign edge weights in the path from node 1 to x such that its total cost is odd.
    Since the answer may be large, return it modulo 109 + 7.
    Note: Ignore all edges not in the path from node 1 to x.


    Example :

    Input: edges = [[1,2]]

    Output: 1

    Explanation:

    The path from Node 1 to Node 2 consists of one edge (1 → 2).
    Assigning weight 1 makes the cost odd, while 2 makes it even. Thus, the number of valid assignments is 1.
*/


function assignEdgeWeights(edges: number[][]): number {
    const MOD = 1000000007n;
    const n = edges.length + 1;

    const graph: number[][] = Array.from({ length: n + 1 }, () => []);

    for (const [u, v] of edges) {
        graph[u].push(v);
        graph[v].push(u);
    }

    const dfs = (node: number, prev: number): number => {
        let dist = 0;

        for (const c of graph[node]) {
            if (c !== prev) {
                dist = Math.max(dist, dfs(c, node) + 1);
            }
        }

        return dist;
    };

    const modPow = (a: number, b: number): bigint => {
        let res = 1n;
        let base = BigInt(a);
        let exp = BigInt(b);

        while (exp > 0n) {
            if (exp & 1n) res = res * base % MOD;
            base = base * base % MOD;
            exp >>= 1n;
        }

        return res;
    };

    const d = dfs(1, 0);

    return Number(modPow(2, d - 1));
};