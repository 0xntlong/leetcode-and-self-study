/**
3607. Power Grid Maintenance
    You are given an integer c representing c power stations, each with a unique identifier id from 1 to c (1‑based indexing).
    These stations are interconnected via n bidirectional cables, represented by a 2D array connections, where each element connections[i] = [ui, vi] indicates a connection between station ui and station vi. Stations that are directly or indirectly connected form a power grid.
    Initially, all stations are online (operational).
    You are also given a 2D array queries, where each query is one of the following two types:
    [1, x]: A maintenance check is requested for station x. If station x is online, it resolves the check by itself. If station x is offline, the check is resolved by the operational station with the smallest id in the same power grid as x. If no operational station exists in that grid, return -1.
    [2, x]: Station x goes offline (i.e., it becomes non-operational).
    Return an array of integers representing the results of each query of type [1, x] in the order they appear.
    Note: The power grid preserves its structure; an offline (non‑operational) node remains part of its grid and taking it offline does not alter connectivity.

    
    Example :
    Input: c = 5, connections = [[1,2],[2,3],[3,4],[4,5]], queries = [[1,3],[2,1],[1,1],[2,2],[1,2]]

    Output: [3,2,3]
    Explanation:

    Initially, all stations {1, 2, 3, 4, 5} are online and form a single power grid.
    Query [1,3]: Station 3 is online, so the maintenance check is resolved by station 3.
    Query [2,1]: Station 1 goes offline. The remaining online stations are {2, 3, 4, 5}.
    Query [1,1]: Station 1 is offline, so the check is resolved by the operational station with the smallest id among {2, 3, 4, 5}, which is station 2.
    Query [2,2]: Station 2 goes offline. The remaining online stations are {3, 4, 5}.
    Query [1,2]: Station 2 is offline, so the check is resolved by the operational station with the smallest id among {3, 4, 5}, which is station 3.
 */





/**
 * @param {number} c
 * @param {number[][]} connections
 * @param {number[][]} queries
 * @return {number[]}
 */
var processQueries = function(c, connections, queries) {
    const parent = Array.from({length: c + 1}, (_, i) => i);
    const find = (i) => {
        while (parent[i] !== i) {
            parent[i] = parent[parent[i]];
            i = parent[i];
        }
        return i;
    };

    for (const [u, v] of connections) {
        const ui = find(u), vi = find(v);
        if (ui !== vi) 
            parent[vi] = ui;
    }

    const nextNode = Array(c + 1).fill(0);
    const compMin = Array(c + 1).fill(0);
    const last = {};
    for (let i = 1; i <= c; i++) {
        const r = find(i);
        if (compMin[r] === 0) 
            compMin[r] = i;
        else 
            nextNode[last[r]] = i;
        last[r] = i;
    }

    const offline = Array(c + 1).fill(false);
    const res = [];

    for (const [t, x] of queries) {
        if (t === 1) {
            if (!offline[x]) 
                res.push(x);
            else {
                const r = find(x);
                const m = compMin[r];
                res.push(m || -1);
            }
        } else {
            if (offline[x]) 
                continue;
            offline[x] = true;
            const r = find(x);
            if (compMin[r] === x) {
                let y = nextNode[x];
                while (y && offline[y]) y = nextNode[y];
                compMin[r] = y;
            }
        }
    }

    return res;
};