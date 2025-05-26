/**
1857. Largest Color Value in a Directed Graph
    There is a directed graph of n colored nodes and m edges. The nodes are numbered from 0 to n - 1.
    You are given a string colors where colors[i] is a lowercase English letter representing the color of the ith node in this graph (0-indexed). You are also given a 2D array edges where edges[j] = [aj, bj] indicates that there is a directed edge from node aj to node bj.
    A valid path in the graph is a sequence of nodes x1 -> x2 -> x3 -> ... -> xk such that there is a directed edge from xi to xi+1 for every 1 <= i < k. The color value of the path is the number of nodes that are colored the most frequently occurring color along that path.
    Return the largest color value of any valid path in the given graph, or -1 if the graph contains a cycle.

    Example :
    Input: colors = "abaca", edges = [[0,1],[0,2],[2,3],[3,4]]
    Output: 3
    Explanation: The path 0 -> 2 -> 3 -> 4 contains 3 nodes that are colored "a" (red in the above image).
 */




/**
 * @param {string} colors
 * @param {number[][]} edges
 * @return {number}
 */
var largestPathValue = function(colors, edges) {
    const n = colors.length;
    const adj = Array.from({length: n }, () => []);
    for (const [u, v] of edges){
        adj[u].push(v);
    }
    const freq = Array.from({length: n}, () => Array(26).fill(0));
    const visited = Array(n).fill(false);
    const cycle = Array(n).fill(false);
    const DFS = (node) => {
        if (cycle[node])
            return Infinity;
        if (visited[node])
            return freq[node][colors.charCodeAt(node) - 97];
        visited[node] = true;
        cycle[node] = true;
        for (const nei of adj[node]){
            if (DFS(nei) === Infinity)
                return Infinity;
            for (let i = 0 ; i < 26; i++){
                freq[node][i] = Math.max(freq[node][i], freq[nei][i]);
            }
        }
        cycle[node] = false;
        freq[node][colors.charCodeAt(node) - 97]++;
        return freq[node][colors.charCodeAt(node) - 97];
    };
    let ans = 0;
    for (let i = 0; i < n; i++){
        const val = DFS(i);
        if (val === Infinity)
            return -1;
        ans = Math.max(ans, val);
    }
    return ans;

};