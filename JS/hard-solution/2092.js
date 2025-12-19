/**
2092. Find All People With Secret
    You are given an integer n indicating there are n people numbered from 0 to n - 1. You are also given a 0-indexed 2D integer array meetings where meetings[i] = [xi, yi, timei] indicates that person xi and person yi have a meeting at timei. A person may attend multiple meetings at the same time. Finally, you are given an integer firstPerson.
    Person 0 has a secret and initially shares the secret with a person firstPerson at time 0. This secret is then shared every time a meeting takes place with a person that has the secret. More formally, for every meeting, if a person xi has the secret at timei, then they will share the secret with person yi, and vice versa.
    The secrets are shared instantaneously. That is, a person may receive the secret and share it with people in other meetings within the same time frame.
    Return a list of all the people that have the secret after all the meetings have taken place. You may return the answer in any order.
    Example :
    Input: n = 6, meetings = [[1,2,5],[2,3,8],[1,5,10]], firstPerson = 1
    Output: [0,1,2,3,5]
    Explanation:
    At time 0, person 0 shares the secret with person 1.
    At time 5, person 1 shares the secret with person 2.
    At time 8, person 2 shares the secret with person 3.
    At time 10, person 1 shares the secret with person 5.​​​​
    Thus, people 0, 1, 2, 3, and 5 know the secret after all the meetings.
 */




/**
 * @param {number} n
 * @param {number[][]} meetings
 * @param {number} firstPerson
 * @return {number[]}
 */
var findAllPeople = function(n, meetings, firstPerson) {
    const timeMap = new Map();
    for (const [x, y, t] of meetings) {
        if (!timeMap.has(t)) timeMap.set(t, []);
        timeMap.get(t).push([x, y]);
    }
    const sortedTimes = Array.from(timeMap.keys()).sort((a, b) => a - b);

    const known = new Array(n).fill(false);
    known[0] = true;
    known[firstPerson] = true;

    for (const t of sortedTimes) {
        const edges = timeMap.get(t);
        const graph = new Map();
        const nodes = new Set();

        for (const [x, y] of edges) {
            if (!graph.has(x)) graph.set(x, []);
            if (!graph.has(y)) graph.set(y, []);
            graph.get(x).push(y);
            graph.get(y).push(x);
            nodes.add(x);
            nodes.add(y);
        }

        const queue = [];
        for (const v of nodes) {
            if (known[v]) queue.push(v);
        }

        while (queue.length) {
            const u = queue.shift();
            for (const v of graph.get(u) || []) {
                if (!known[v]) {
                    known[v] = true;
                    queue.push(v);
                }
            }
        }
    }

    const res = [];
    for (let i = 0; i < n; i++) {
        if (known[i]) res.push(i);
    }
    return res;
};