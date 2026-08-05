/**
3310. Remove Methods From Project
    You are maintaining a project that has n methods numbered from 0 to n - 1.
    You are given two integers n and k, and a 2D integer array invocations, where invocations[i] = [ai, bi] indicates that method ai invokes method bi
    There is a known bug in method k. Method k, along with any method invoked by it, either directly or indirectly, are considered suspicious and we aim to remove them.
    A group of methods can only be removed if no method outside the group invokes any methods within it.
    Return an array containing all the remaining methods after removing all the suspicious methods. You may return the answer in any order. If it is not possible to remove all the suspicious methods, none should be removed.
    Example :
    Input: n = 4, k = 1, invocations = [[1,2],[0,1],[3,2]]
    Output: [0,1,2,3]
    Explanation:
    Method 2 and method 1 are suspicious, but they are directly invoked by methods 3 and 0, which are not suspicious. We return all elements without removing anything.
 */





function remainingMethods(n: number, k: number, invocations: number[][]): number[] {
    const adj: number[][] = Array.from(
        { length: n },
        () => []
    );

    for (const [u, v] of invocations) {
        adj[u].push(v);
    }

    const suspicious: boolean[] = Array(n).fill(false);
    suspicious[k] = true;

    const queue: number[] = [k];
    let head = 0;

    while (head < queue.length) {
        const u = queue[head++];

        for (const v of adj[u]) {
            if (!suspicious[v]) {
                suspicious[v] = true;
                queue.push(v);
            }
        }
    }

    for (const [u, v] of invocations) {
        if (!suspicious[u] && suspicious[v]) {
            return Array.from(
                { length: n },
                (_, i) => i
            );
        }
    }

    const result: number[] = [];

    for (let i = 0; i < n; i++) {
        if (!suspicious[i]) {
            result.push(i);
        }
    }

    return result;
};