/**
3505. Minimum Operations to Make Elements Within K Subarrays Equal
    You are given an integer array nums and two integers, x and k. You can perform the following operation any number of times (including zero):
    Increase or decrease any element of nums by 1.
    Return the minimum number of operations needed to have at least k non-overlapping subarrays of size exactly x in nums, where all elements within each subarray are equal.
    Example :
    Input: nums = [5,-2,1,3,7,3,6,4,-1], x = 3, k = 2
    Output: 8
    Explanation:
    Use 3 operations to add 3 to nums[1] and use 2 operations to subtract 2 from nums[3]. The resulting array is [5, 1, 1, 1, 7, 3, 6, 4, -1].
    Use 1 operation to add 1 to nums[5] and use 2 operations to subtract 2 from nums[6]. The resulting array is [5, 1, 1, 1, 7, 4, 4, 4, -1].
    Now, all elements within each subarray [1, 1, 1] (from indices 1 to 3) and [4, 4, 4] (from indices 5 to 7) are equal. Since 8 total operations were used, 8 is the output.
 */



/**
 * @param {number[]} nums
 * @param {number} x
 * @param {number} k
 * @return {number}
 */
var minOperations = function(nums, x, k) {
    const n = nums.length;
    if (x * k > n) return -1;

    const vals = [...new Set([...nums].sort((a, b) => a - b))];
    const m = vals.length;

    const index = new Map();
    vals.forEach((v, i) => index.set(v, i + 1));

    const cnt = new Float64Array(m + 1);
    const sum = new Float64Array(m + 1);

    function update(p, delta, value) {
        while (p <= m) {
            cnt[p] += delta;
            sum[p] += delta * value;
            p += p & -p;
        }
    }

    function query(p) {
        let c = 0, s = 0;

        while (p > 0) {
            c += cnt[p];
            s += sum[p];
            p -= p & -p;
        }

        return [c, s];
    }

    function kth(rank) {
        let p = 0;
        let step = 1;

        while (step * 2 <= m) step *= 2;

        while (step > 0) {
            const np = p + step;

            if (np <= m && cnt[np] < rank) {
                rank -= cnt[np];
                p = np;
            }

            step = Math.floor(step / 2);
        }

        return p + 1;
    }

    const ops = new Array(n).fill(0);
    let total = 0;

    for (let i = 0; i < n; i++) {
        update(index.get(nums[i]), 1, nums[i]);
        total += nums[i];

        if (i >= x) {
            update(index.get(nums[i - x]), -1, nums[i - x]);
            total -= nums[i - x];
        }

        if (i >= x - 1) {
            const midPos = kth(Math.floor((x + 1) / 2));
            const mid = vals[midPos - 1];

            const [lc, ls] = query(midPos);
            const rc = x - lc;
            const rs = total - ls;

            ops[i] = mid * lc - ls + rs - mid * rc;
        }
    }

    let pre = new Array(n + 1).fill(0);
    let cur = new Array(n + 1).fill(Infinity);

    for (let j = 1; j <= k; j++) {
        cur.fill(Infinity);

        for (let i = j * x; i <= n; i++) {
            cur[i] = Math.min(
                cur[i - 1],
                pre[i - x] + ops[i - 1]
            );
        }

        [pre, cur] = [cur, pre];
    }

    return pre[n];
};