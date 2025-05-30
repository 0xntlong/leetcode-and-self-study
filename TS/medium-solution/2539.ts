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


function closestMeetingNode(edges: number[], node1: number, node2: number): number {
    const n = edges.length;
    const dist1 : number[] = new Array(n).fill(-1);
    const dist2 : number[] = new Array(n).fill(-1);
    const DFS = (start : number, dist : number[]) => {
        let curr = start;
        let d = 0;
        while (curr !== -1 && dist[curr] === -1){
            dist[curr] = d++;
            curr = edges[curr];
        }
    }
    DFS(node1, dist1);
    DFS(node2, dist2);
    let res = -1;
    let minDist = Infinity;
    for (let i = 0; i < n; i++){
        if (dist1[i] !== -1 && dist2[i] !== -1){
            const maxDist = Math.max(dist1[i], dist2[i]);
            if (maxDist < minDist || (maxDist === minDist && i < res)){
                minDist = maxDist;
                res = i;
            }
        }
    }
    return res;
};