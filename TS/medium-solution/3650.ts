/**
3650. Minimum Cost Path with Edge Reversals
    You are given a directed, weighted graph with n nodes labeled from 0 to n - 1, and an array edges where edges[i] = [ui, vi, wi] represents a directed edge from node ui to node vi with cost wi.
    Each node ui has a switch that can be used at most once: when you arrive at ui and have not yet used its switch, you may activate it on one of its incoming edges vi → ui reverse that edge to ui → vi and immediately traverse it.
    The reversal is only valid for that single move, and using a reversed edge costs 2 * wi.
    Return the minimum total cost to travel from node 0 to node n - 1. If it is not possible, return -1.

    Example :
    Input: n = 4, edges = [[0,1,3],[3,1,1],[2,3,4],[0,2,2]]
    Output: 5
    Explanation:
    Use the path 0 → 1 (cost 3).
    At node 1 reverse the original edge 3 → 1 into 1 → 3 and traverse it at cost 2 * 1 = 2.
    Total cost is 3 + 2 = 5.
 */


function minCost(n: number, edges: number[][]): number {
    const graph: Array<Array<[number, number]>> = Array.from({ length: n }, () => []);
    for (const [u, v, w] of edges) {
        graph[u].push([v, w]);
        graph[v].push([u, 2 * w]);
    }

    class MinHeap {
        h: Array<[number, number]> = [];
        less(a: [number, number], b: [number, number]): boolean {
            return a[0] < b[0] || (a[0] === b[0] && a[1] < b[1]);
        }
        push(x: [number, number]) {
            const h = this.h;
            h.push(x);
            let i = h.length - 1;
            while (i > 0) {
                const p = (i - 1) >> 1;
                if (this.less(h[p], h[i])) 
                    break;
                [h[p], h[i]] = [h[i], h[p]];
                i = p;
            }
        }
        pop(): [number, number] {
            const h = this.h;
            const res = h[0];
            const last = h.pop() as [number, number];
            if (h.length) {
                h[0] = last;
                let i = 0;
                while (true) {
                    let l = i * 2 + 1, r = l + 1, s = i;
                    if (l < h.length && this.less(h[l], h[s])) s = l;
                    if (r < h.length && this.less(h[r], h[s])) s = r;
                    if (s === i) 
                        break;
                    [h[s], h[i]] = [h[i], h[s]];
                    i = s;
                }
            }
            return res;
        }
        size(): number { return this.h.length; }
    }

    const ans: number[] = new Array(n).fill(Number.POSITIVE_INFINITY);
    ans[0] = 0;

    const pq = new MinHeap();
    pq.push([0, 0]);

    while (pq.size()) {
        const [weight, node] = pq.pop();
        if (weight > ans[node]) 
            continue;

        for (const [nd, wt] of graph[node]) {
            if (wt + weight < ans[nd]) {
                ans[nd] = wt + weight;
                pq.push([ans[nd], nd]);
            }
        }
    }

    return ans[n - 1] === Number.POSITIVE_INFINITY ? -1 : ans[n - 1];
};