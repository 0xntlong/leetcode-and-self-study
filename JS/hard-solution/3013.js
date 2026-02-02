/**
3013. Divide an Array Into Subarrays With Minimum Cost II
    You are given a 0-indexed array of integers nums of length n, and two positive integers k and dist.
    The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.
    You need to divide nums into k disjoint contiguous subarrays, such that the difference between the starting index of the second subarray and the starting index of the kth subarray should be less than or equal to dist. In other words, if you divide nums into the subarrays nums[0..(i1 - 1)], nums[i1..(i2 - 1)], ..., nums[ik-1..(n - 1)], then ik-1 - i1 <= dist.
    Return the minimum possible sum of the cost of these subarrays.
    Example :
    Input: nums = [1,3,2,6,4,2], k = 3, dist = 3
    Output: 5
    Explanation: The best possible way to divide nums into 3 subarrays is: [1,3], [2,6,4], and [2]. This choice is valid because ik-1 - i1 is 5 - 2 = 3 which is equal to dist. The total cost is nums[0] + nums[2] + nums[5] which is 1 + 2 + 2 = 5.
    It can be shown that there is no possible way to divide nums into 3 subarrays at a cost lower than 5.
 */


/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} dist
 * @return {number}
 */
var minimumCost = function(nums, k, dist) {
    const n = nums.length;
    let sum = 0;
    let ans = Number.MAX_SAFE_INTEGER;
    const used = new Set();

    const heapUsed = new MaxPriorityQueue({
        compare: (a, b) => b[0] - a[0]  
    });

    const heapUnused = new MinPriorityQueue({
        compare: (a, b) => a[0] - b[0]   
    });

    for (let right = 1; right < n; right++) {
        const left = right - dist - 1;

        if (left > 0 && used.has(left)) {
            used.delete(left);
            sum -= nums[left];

            while (!heapUnused.isEmpty() && heapUnused.front()[1] < left) {
                heapUnused.dequeue();
            }

            if (!heapUnused.isEmpty()) {
                const [val, idx] = heapUnused.dequeue();
                heapUsed.enqueue([val, idx]);
                used.add(idx);
                sum += val;
            }
        }
        if (used.size < k - 1) {
            heapUsed.enqueue([nums[right], right]);
            used.add(right);
            sum += nums[right];
        } else {
            while (!heapUsed.isEmpty() && !used.has(heapUsed.front()[1])) {
                heapUsed.dequeue();
            }

            if (!heapUsed.isEmpty() && nums[right] < heapUsed.front()[0]) {
                const [val, idx] = heapUsed.dequeue();
                used.delete(idx);
                heapUnused.enqueue([val, idx]);

                heapUsed.enqueue([nums[right], right]);
                used.add(right);
                sum += nums[right] - val;
            } else {
                heapUnused.enqueue([nums[right], right]);
            }
        }

        if (left >= 0) {
            ans = Math.min(ans, sum);
        }
    }

    return nums[0] + ans;
};