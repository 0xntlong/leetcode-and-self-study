/**
1340. Jump Game V
    Given an array of integers arr and an integer d. In one step you can jump from index i to index:
    i + x where: i + x < arr.length and  0 < x <= d.
    i - x where: i - x >= 0 and  0 < x <= d.
    In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).
    You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.
    Notice that you can not jump outside of the array at any time.

    Example :
    Input: arr = [6,4,14,6,8,13,9,7,10,6,12], d = 2
    Output: 4
    Explanation: You can start at index 10. You can jump 10 --> 8 --> 6 --> 7 as shown.
    Note that if you start at index 6 you can only jump to index 7. You cannot jump to index 5 because 13 > 9. You cannot jump to index 4 because index 5 is between index 4 and 6 and 13 > 9.
    Similarly You cannot jump from index 3 to index 2 or index 1.
 */



function maxJumps(arr: number[], d: number): number {
    const n = arr.length;
    const steps: number[] = new Array(n).fill(1);
    const stack: number[] = [];
    for (let i = 0; i <= n; i++) {
        while (stack.length > 0 && (i === n || arr[stack[stack.length - 1]] < arr[i])) {
            const popIndices: number[] = [stack.pop()!];
            while (
                stack.length > 0 &&
                arr[stack[stack.length - 1]] === arr[popIndices[0]]
            ) {
                popIndices.push(stack.pop()!);
            }
            for (const j of popIndices) {
                if (i < n && i - j <= d) {
                    steps[i] = Math.max(steps[i], steps[j] + 1);
                }
                if (stack.length > 0 && j - stack[stack.length - 1] <= d) {
                    const leftIdx = stack[stack.length - 1];
                    steps[leftIdx] = Math.max(steps[leftIdx], steps[j] + 1);
                }
            }
        }
        if (i < n) {
            stack.push(i);
        }
    }
    return Math.max(...steps);
}