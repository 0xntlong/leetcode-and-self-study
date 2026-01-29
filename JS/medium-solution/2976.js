/**
2976. Minimum Cost to Convert String I
    You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] represents the cost of changing the character original[i] to the character changed[i].
    You start with the string source. In one operation, you can pick a character x from the string and change it to the character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.
    Return the minimum cost to convert the string source to the string target using any number of operations. If it is impossible to convert source to target, return -1.
    Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].

    Example :
    Input: source = "abcd", target = "acbe", original = ["a","b","c","c","e","d"], changed = ["b","c","b","e","b","e"], cost = [2,5,5,1,2,20]
    Output: 28
    Explanation: To convert the string "abcd" to string "acbe":
    - Change value at index 1 from 'b' to 'c' at a cost of 5.
    - Change value at index 2 from 'c' to 'e' at a cost of 1.
    - Change value at index 2 from 'e' to 'b' at a cost of 2.
    - Change value at index 3 from 'd' to 'e' at a cost of 20.
    The total cost incurred is 5 + 1 + 2 + 20 = 28.
    It can be shown that this is the minimum possible cost.

*/

/**
 * @param {string} source
 * @param {string} target
 * @param {character[]} original
 * @param {character[]} changed
 * @param {number[]} cost
 * @return {number}
 */
var minimumCost = function(source, target, original, changed, cost) {
    const INF = Number.MAX_SAFE_INTEGER;
    const N = 26;

    const graph = Array.from({ length: N }, () => []);
    for (let i = 0; i < cost.length; i++) {
        const u = original[i].charCodeAt(0) - 97;
        const v = changed[i].charCodeAt(0) - 97;
        graph[u].push([v, cost[i]]);
    }

    function dijkstra(start) {
        const dist = Array(N).fill(INF);
        const used = Array(N).fill(false);
        dist[start] = 0;

        for (let i = 0; i < N; i++) {
            let u = -1;
            for (let j = 0; j < N; j++) {
                if (!used[j] && (u === -1 || dist[j] < dist[u])) {
                    u = j;
                }
            }
            if (u === -1 || dist[u] === INF) 
                break;
            used[u] = true;

            for (const [v, w] of graph[u]) {
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }
        return dist;
    }

    const allDist = Array.from({ length: N }, () => Array(N));
    for (let i = 0; i < N; i++) {
        allDist[i] = dijkstra(i);
    }

    let total = 0;
    for (let i = 0; i < source.length; i++) {
        const s = source.charCodeAt(i) - 97;
        const t = target.charCodeAt(i) - 97;
        if (allDist[s][t] === INF) 
            return -1;
        total += allDist[s][t];
    }

    return total;
};