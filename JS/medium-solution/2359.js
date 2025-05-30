/**
2359. Find Closest Node to Given Two Nodes
    You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.
    The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from i, then edges[i] == -1.
    You are also given two integers node1 and node2.
    Return the index of the node that can be reached from both node1 and node2, such that the maximum between the distance from node1 to that node, and from node2 to that node is minimized. If there are multiple answers, return the node with the smallest index, and if no possible answer exists, return -1.
    Note that edges may contain cycles.

    Example :
    Input: edges = [2,2,3,-1], node1 = 0, node2 = 1
    Output: 2
    Explanation: The distance from node 0 to node 2 is 1, and the distance from node 1 to node 2 is 1.
    The maximum of those two distances is 1. It can be proven that we cannot get a node with a smaller maximum distance than 1, so we return node 2.
 */



/**
 * @param {number[]} edges
 * @param {number} node1
 * @param {number} node2
 * @return {number}
 */
var closestMeetingNode = function(edges, node1, node2) {
    function BFS(start){
        const n = edges.length;
        const dist = new Array(n).fill(-1);
        const queue = [[start, 0]];
        const visited = new Array(n).fill(false);
        while (queue.length > 0){
            const [node, d] = queue.shift();
            if (visited[node]){
                continue;
            }
            visited[node] = true;
            dist[node] = d;
            const nextNode = edges[node];
            if (nextNode !== -1 && !visited[nextNode]){
                queue.push([nextNode, d + 1]);
            }
        }
        return dist;
    }
    const dist1 = BFS(node1);
    const dist2 = BFS(node2);
    let minDist = Infinity;
    let res = -1;
    for (let i = 0; i < edges.length; i++){
        if (dist1[i] !== -1 && dist2[i] !== -1){
            const maxDist = Math.max(dist1[i],dist2[i]);
            if (maxDist < minDist){
                minDist = maxDist;
                res = i;
            }
        }
    }
    return res;
};