/**
3600. Maximize Spanning Tree Stability with Upgrades
    You are given an integer n, representing n nodes numbered from 0 to n - 1 and a list of edges, where edges[i] = [ui, vi, si, musti]:
    ui and vi indicates an undirected edge between nodes ui and vi.
    si is the strength of the edge.
    musti is an integer (0 or 1). If musti == 1, the edge must be included in the spanning tree. These edges cannot be upgraded.
    You are also given an integer k, the maximum number of upgrades you can perform. Each upgrade doubles the strength of an edge, and each eligible edge (with musti == 0) can be upgraded at most once.
    The stability of a spanning tree is defined as the minimum strength score among all edges included in it.
    Return the maximum possible stability of any valid spanning tree. If it is impossible to connect all nodes, return -1.
    Note: A spanning tree of a graph with n nodes is a subset of the edges that connects all nodes together (i.e. the graph is connected) without forming any cycles, and uses exactly n - 1 edges.

    Example :

    Input: n = 3, edges = [[0,1,2,1],[1,2,3,0]], k = 1

    Output: 2

    Explanation:

    Edge [0,1] with strength = 2 must be included in the spanning tree.
    Edge [1,2] is optional and can be upgraded from 3 to 6 using one upgrade.
    The resulting spanning tree includes these two edges with strengths 2 and 6.
    The minimum strength in the spanning tree is 2, which is the maximum possible stability.
*/



function maxStability(n: number, edges: number[][], k: number): number {
    const parent = Array(n).fill(0).map((_, idx) => idx);
    const size = Array(n).fill(1);

    function find(v: number): number {
        if (parent[v] === v) return v;
        parent[v] = find(parent[v]);
        return parent[v];
    }

    function union(a: number, b: number): boolean {
        a = find(a);
        b = find(b);
        if (a !== b) {
            if (size[a] < size[b]) {
                [a, b] = [b, a];
            }
            parent[b] = a;
            size[a] += size[b];
            return true;
        }
        return false;
    }

    let comp = n;
    let res = Number.MAX_VALUE;
    let opt: number[] = [];

    for (let i = 0; i < edges.length; i++) {
        if (edges[i][3] === 1) {
            if (union(edges[i][0], edges[i][1])) {
                comp--;
                res = Math.min(res, edges[i][2]);
            } else {
                return -1;
            }
        }
    }

    if (comp === 1) {
        return res;
    }

    for (let i = 0; i < edges.length; i++) {
        if (edges[i][3] === 0) {
            opt.push(i);
        }
    }

    opt.sort((a, b) => edges[b][2] - edges[a][2]);

    let stab: number[] = [];

    for (let i of opt) {
        if (union(edges[i][0], edges[i][1])) {
            comp--;
            stab.push(edges[i][2]);
            if (comp === 1) {
                break;
            }
        }
    }

    if (comp > 1) {
        return -1;
    }

    for (let i = 1; i <= Math.min(stab.length, k); i++) {
        stab[stab.length - i] *= 2;
    }

    let minStab = Math.min(...stab);

    return Math.min(res, minStab);
};