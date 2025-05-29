/**
3373. Maximize the Number of Target Nodes After Connecting Trees II
    There exist two undirected trees with n and m nodes, labeled from [0, n - 1] and [0, m - 1], respectively.
    You are given two 2D integer arrays edges1 and edges2 of lengths n - 1 and m - 1, respectively, where edges1[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the first tree and edges2[i] = [ui, vi] indicates that there is an edge between nodes ui and vi in the second tree.
    Node u is target to node v if the number of edges on the path from u to v is even. Note that a node is always target to itself.
    Return an array of n integers answer, where answer[i] is the maximum possible number of nodes that are target to node i of the first tree if you had to connect one node from the first tree to another node in the second tree.
    Note that queries are independent from each other. That is, for every query you will remove the added edge before proceeding to the next query.

    Example 1:
    Input: edges1 = [[0,1],[0,2],[2,3],[2,4]], edges2 = [[0,1],[0,2],[0,3],[2,7],[1,4],[4,5],[4,6]]
    Output: [8,7,7,8,8]
    Explanation:
    For i = 0, connect node 0 from the first tree to node 0 from the second tree.
    For i = 1, connect node 1 from the first tree to node 4 from the second tree.
    For i = 2, connect node 2 from the first tree to node 7 from the second tree.
    For i = 3, connect node 3 from the first tree to node 0 from the second tree.
    For i = 4, connect node 4 from the first tree to node 4 from the second tree.
 */

// Was Removed 's' from maxTargetNodes for not had red underline in VSCode
function maxTargetNode(edges1: number[][], edges2: number[][]): number[] {
    const buildAdj = (edges: number[][], n: number): number[][] => {
        const graph: number[][] = Array.from({ length: n }, () => []);
        for (const [u, v] of edges) {
            graph[u].push(v);
            graph[v].push(u);
        }
        return graph;
    };

    const findEven = (edges: number[][], n: number): boolean[] => {
        const graph = buildAdj(edges, n);
        const evens: boolean[] = new Array(n).fill(false);
        const queue: [number, number, boolean][] = [[0, -1, true]];

        while (queue.length) {
            const [node, parent, isEven] = queue.shift()!;
            evens[node] = isEven;
            for (const child of graph[node]) {
                if (child !== parent) {
                    queue.push([child, node, !isEven]);
                }
            }
        }
        return evens;
    };

    const n1 = edges1.length + 1;
    const n2 = edges2.length + 1;

    const even1 = findEven(edges1, n1);
    const even2 = findEven(edges2, n2);

    const total1 = even1.filter(b => b).length;
    const total2 = even2.filter(b => b).length;
    const mx = Math.max(total2, n2 - total2);

    return even1.map(even => mx + (even ? total1 : n1 - total1));
}