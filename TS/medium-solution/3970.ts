/**
3970. Shortest Path With At Most K Consecutive Identical Characters
    You are given an integer n representing the number of nodes in a directed weighted graph, numbered from 0 to n - 1. This is represented by a 2D integer array edges, where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with weight wi.
    You are also given a string labels of length n, where labels[i] is the character assigned to node i, and an integer k.
    Return the minimum total edge weight of a path from node 0 to node n - 1 such that the concatenation of the labels of the nodes along the path contains at most k consecutive identical characters. If no valid path exists, return -1.

    Example :
    Input: n = 3, edges = [[0,1,1],[1,2,1],[0,2,3]], labels = "aab", k = 1
    Output: 3
    Explanation:
    The optimal valid path from node 0 to node 2 is as follows:
    Use edges[2] = [0, 2, 3] to reach node 2 with a weight wi = 3.
    The corresponding concatenation of labels is "ab", which satisfies at most k = 1 consecutive identical characters. Thus, the answer is 3.
 */



function shortestPath(n: number, edges: number[][], labels: string, k: number): number {
    type Edge = [number, number, boolean];
    type State = [number, number, number];

    const graph: Edge[][] = Array.from({ length: n }, () => []);

    for (const [u, v, w] of edges) {
        graph[u].push([v, w, labels[u] === labels[v]]);
    }

    const done: number[] = Array(n).fill(k + 1);
    const heap: State[] = [];

    function less(a: State, b: State): boolean {
        if (a[0] !== b[0]) return a[0] < b[0];
        if (a[1] !== b[1]) return a[1] < b[1];
        return a[2] < b[2];
    }

    function push(value: State): void {
        let i = heap.length;
        heap.push(value);

        while (i > 0) {
            const p = Math.floor((i - 1) / 2);
            if (!less(value, heap[p])) break;

            heap[i] = heap[p];
            i = p;
        }

        heap[i] = value;
    }

    function pop(): State {
        const result = heap[0];
        const last = heap.pop()!;

        if (heap.length === 0) return result;

        let i = 0;

        while (2 * i + 1 < heap.length) {
            let child = 2 * i + 1;

            if (
                child + 1 < heap.length &&
                less(heap[child + 1], heap[child])
            ) {
                child++;
            }

            if (!less(heap[child], last)) break;

            heap[i] = heap[child];
            i = child;
        }

        heap[i] = last;
        return result;
    }

    push([0, 0, 1]);

    while (heap.length > 0) {
        const [d, u, r] = pop();

        if (r >= done[u]) continue;
        done[u] = r;

        if (u === n - 1) return d;

        for (const [v, w, same] of graph[u]) {
            const nr = same ? r + 1 : 1;

            if (nr < done[v]) {
                push([d + w, v, nr]);
            }
        }
    }

    return -1;
};