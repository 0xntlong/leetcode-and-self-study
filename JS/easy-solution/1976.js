/**
1976. Number of Ways to Arrive at Destination
    You are in a city that consists of n intersections numbered from 0 to n - 1 with bi-directional roads between some intersections. The inputs are generated such that you can reach any intersection from any other intersection and that there is at most one road between any two intersections.
    You are given an integer n and a 2D integer array roads where roads[i] = [ui, vi, timei] means that there is a road between intersections ui and vi that takes timei minutes to travel. You want to know in how many ways you can travel from intersection 0 to intersection n - 1 in the shortest amount of time.
    Return the number of ways you can arrive at your destination in the shortest amount of time. Since the answer may be large, return it modulo 109 + 7.

    Example :
    Input: n = 7, roads = [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]
    Output: 4
    Explanation: The shortest amount of time it takes to go from intersection 0 to intersection 6 is 7 minutes.
    The four ways to get there in 7 minutes are:
    - 0 ➝ 6
    - 0 ➝ 4 ➝ 6
    - 0 ➝ 1 ➝ 2 ➝ 5 ➝ 6
    - 0 ➝ 1 ➝ 3 ➝ 5 ➝ 6
 */


/**
 * @param {number} n
 * @param {number[][]} roads
 * @return {number}
 */
var countPaths = function(n, roads) {
    const graph = Array.from({ length: n }, () => []);
    for (let [u, v, time] of roads) {
        graph[u].push([v, time]);
        graph[v].push([u, time]);
    }

    const MOD = 1e9 + 7;
    const distance = new Array(n).fill(Infinity);
    const count = new Array(n).fill(0);
    distance[0] = 0;
    count[0] = 1;

    const pq = [[0, 0]]; 
    while (pq.length > 0) {
        pq.sort((a, b) => a[0] - b[0]); 
        const [dist, u] = pq.shift();

        if (dist > distance[u]) 
            continue;

        for (let [v, time] of graph[u]) {
            const newDist = dist + time;

            if (newDist < distance[v]) {
                distance[v] = newDist;
                count[v] = count[u];
                pq.push([newDist, v]);
            } else if (newDist === distance[v]) {
                count[v] = (count[v] + count[u]) % MOD;
            }
        }
    }

    return count[n - 1];
};