/**
1345. Jump Game IV
    Given an array of integers arr, you are initially positioned at the first index of the array.
    In one step you can jump from index i to index:
    i + 1 where: i + 1 < arr.length.
    i - 1 where: i - 1 >= 0.
    j where: arr[i] == arr[j] and i != j.
    Return the minimum number of steps to reach the last index of the array.
    Notice that you can not jump outside of the array at any time.
    Example :
    Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
    Output: 3
    Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
 */



function minJumps(arr: number[]): number {
    const n = arr.length;
    if (n === 1)
        return 0;
    const graph = new Map();
    for (let i = 0; i < n; i++) {
        if (!graph.has(arr[i])) {
            graph.set(arr[i], []);
        }
        graph.get(arr[i]).push(i);
    }
    const q = [0];
    const visited = new Array(n).fill(false);
    visited[0] = true;
    let head = 0;
    let cnt = 0;
    while (head < q.length) {
        let size = q.length - head;
        while (size--) {
            const idx = q[head++];
            if (idx === n - 1)
                return cnt;
            if (idx - 1 >= 0 && !visited[idx - 1]) {
                visited[idx - 1] = true;
                q.push(idx - 1);
            }
            if (idx + 1 < n && !visited[idx + 1]) {
                visited[idx + 1] = true;
                q.push(idx + 1);
            }
            if (graph.has(arr[idx])) {
                for (const nxt of graph.get(arr[idx])) {
                    if (!visited[nxt]) {
                        visited[nxt] = true;
                        q.push(nxt)
                    }
                }
                graph.delete(arr[idx]);
            }
        }
        cnt++;
    }
    return -1;
};