/**
1306. Jump Game III
    Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach any index with value 0.
    Notice that you can not jump outside of the array at any time.
    Example :
    Input: arr = [4,2,3,0,3,1,2], start = 5
    Output: true
    Explanation: 
    All possible ways to reach at index 3 with value 0 are: 
    index 5 -> index 4 -> index 1 -> index 3 
    index 5 -> index 6 -> index 4 -> index 1 -> index 3 
 */


function canReach(arr: number[], start: number): boolean {
    const n = arr.length;
    const q: number[] = [start];
    let head = 0;
    const visited: boolean[] = new Array(n).fill(false);
    visited[start] = true;
    while (head < q.length) {
        const node = q[head++];
        if (arr[node] === 0)
            return true;
        const l = node - arr[node];
        const r = node + arr[node];
        if (l >= 0 && !visited[l]) {
            q.push(l);
            visited[l] = true;
        }
        if (r < n && !visited[r]) {
            q.push(r);
            visited[r] = true;
        }
    }
    return false;
};