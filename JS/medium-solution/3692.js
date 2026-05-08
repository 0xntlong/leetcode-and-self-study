/**
3629. Minimum Jumps to Reach End via Prime Teleportation
    You are given an integer array nums of length n.
    You start at index 0, and your goal is to reach index n - 1.
    From any index i, you may perform one of the following operations:
    Adjacent Step: Jump to index i + 1 or i - 1, if the index is within bounds.
    Prime Teleportation: If nums[i] is a prime number p, you may instantly jump to any index j != i such that nums[j] % p == 0.
    Return the minimum number of jumps required to reach index n - 1.
    Example :
    Input: nums = [1,2,4,6]
    Output: 2
    Explanation:
    One optimal sequence of jumps is:
    Start at index i = 0. Take an adjacent step to index 1.
    At index i = 1, nums[1] = 2 is a prime number. Therefore, we teleport to index i = 3 as nums[3] = 6 is divisible by 2.
 */


/**
 * @param {number[]} nums
 * @return {number}
 */
var minJumps = function(nums) {
    const n = nums.length;
    if (n <= 1) 
        return 0;

    const port = new Map();

    for (let i = 0; i < n; i++) {
        let tmp = nums[i];
        for (let d = 2; d * d <= tmp; d++) {
            if (tmp % d === 0) {
                if (!port.has(d)) 
                    port.set(d, []);
                port.get(d).push(i);
                while (tmp % d === 0) 
                    tmp /= d;
            }
        }
        if (tmp > 1) {
            if (!port.has(tmp)) 
                port.set(tmp, []);
            port.get(tmp).push(i);
        }
    }

    const visited = new Uint8Array(n); 
    const q = new Int32Array(n); 
    let head = 0;
    let tail = 0;

    q[tail++] = 0;
    visited[0] = 1;
    let steps = 0;

    while (head < tail) {
        let sz = tail - head;
        while (sz--) {
            const i = q[head++];
            if (i === n - 1) 
                return steps;
            const num = nums[i];

            if (port.has(num)) {
                const neighbors = port.get(num);
                for (let k = 0; k < neighbors.length; k++) {
                    const nei = neighbors[k];
                    if (!visited[nei]) {
                        visited[nei] = 1;
                        q[tail++] = nei;
                    }
                }
                port.delete(num); 
            }

            if (i + 1 < n && !visited[i + 1]) {
                visited[i + 1] = 1;
                q[tail++] = i + 1;
            }


            if (i - 1 >= 0 && !visited[i - 1]) {
                visited[i - 1] = 1;
                q[tail++] = i - 1;
            }
        }
        steps++;
    }

    return steps;
};