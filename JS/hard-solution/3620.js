/**
3620. Network Recovery Pathways
    You are given a directed acyclic graph of n nodes numbered from 0 to n − 1. This is represented by a 2D array edges of length m, where edges[i] = [ui, vi, costi] indicates a one‑way communication from node ui to node vi with a recovery cost of costi.
    Some nodes may be offline. You are given a boolean array online where online[i] = true means node i is online. Nodes 0 and n − 1 are always online.
    A path from 0 to n − 1 is valid if:
    All intermediate nodes on the path are online.
    The total recovery cost of all edges on the path does not exceed k.
    For each valid path, define its score as the minimum edge‑cost along that path.
    Return the maximum path score (i.e., the largest minimum-edge cost) among all valid paths. If no valid path exists, return -1.
    
    Example 1:
    Input: edges = [[0,1,5],[1,3,10],[0,2,3],[2,3,4]], online = [true,true,true,true], k = 10
    Output: 3
    Explanation:
    The graph has two possible routes from node 0 to node 3:
    Path 0 → 1 → 3
    Total cost = 5 + 10 = 15, which exceeds k (15 > 10), so this path is invalid.
    Path 0 → 2 → 3
    Total cost = 3 + 4 = 7 <= k, so this path is valid.
    The minimum edge‐cost along this path is min(3, 4) = 3.
    There are no other valid paths. Hence, the maximum among all valid path‐scores is 3.
 */



/**
 * @param {number[][]} edges
 * @param {boolean[]} online
 * @param {number} k
 * @return {number}
 */
var findMaxPathScore = function(edges, online, k) {
    class MinHeap {
        constructor() {
            this.heap = [];
        }

        push(node) {
            this.heap.push(node);
            let i = this.heap.length - 1;

            while (i > 0) {
                const p = Math.floor((i - 1) / 2);

                if (this.heap[p][0] <= this.heap[i][0])
                    break;

                [this.heap[p], this.heap[i]] = [this.heap[i], this.heap[p]];
                i = p;
            }
        }

        pop() {
            if (this.heap.length === 1)
                return this.heap.pop();

            const top = this.heap[0];
            this.heap[0] = this.heap.pop();

            let i = 0;

            while (true) {
                let l = i * 2 + 1;
                let r = i * 2 + 2;
                let best = i;

                if (l < this.heap.length && this.heap[l][0] < this.heap[best][0])
                    best = l;

                if (r < this.heap.length && this.heap[r][0] < this.heap[best][0])
                    best = r;

                if (best === i)
                    break;

                [this.heap[i], this.heap[best]] = [this.heap[best], this.heap[i]];
                i = best;
            }

            return top;
        }

        size() {
            return this.heap.length;
        }
    }

    let maxWeight = 0;
    const graph = new Map();

    for (const [fromNode, toNode, weight] of edges) {
        if (!graph.has(fromNode)) {
            graph.set(fromNode, []);
        }

        graph.get(fromNode).push([toNode, weight]);
        maxWeight = Math.max(maxWeight, weight);
    }

    const check = (minWeight) => {
        const heap = new MinHeap();
        heap.push([0, 0]);

        const bestCost = new Map();

        while (heap.size() > 0) {
            const [currentCost, currentNode] = heap.pop();

            if (currentNode === online.length - 1) {
                return true;
            }

            if (bestCost.has(currentNode) && bestCost.get(currentNode) <= currentCost) {
                continue;
            }

            bestCost.set(currentNode, currentCost);

            for (const [nextNode, edgeWeight] of (graph.get(currentNode) || [])) {
                if (currentCost + edgeWeight > k) {
                    continue;
                }

                if (!online[nextNode]) {
                    continue;
                }

                if (edgeWeight < minWeight) {
                    continue;
                }

                heap.push([currentCost + edgeWeight, nextNode]);
            }
        }

        return false;
    };

    let left = -1;
    let right = maxWeight + 1;

    while (left <= right) {
        const mid = Math.floor((left + right) / 2);

        if (check(mid)) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return right >= 0 ? right : -1;
};