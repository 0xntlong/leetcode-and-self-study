/**
3525. Find X Value of Array II
    You are given an array of positive integers nums and a positive integer k. You are also given a 2D array queries, where queries[i] = [indexi, valuei, starti, xi].
    You are allowed to perform an operation once on nums, where you can remove any suffix from nums such that nums remains non-empty.
    The x-value of nums for a given x is defined as the number of ways to perform this operation so that the product of the remaining elements leaves a remainder of x modulo k.
    For each query in queries you need to determine the x-value of nums for xi after performing the following actions:
    Update nums[indexi] to valuei. Only this step persists for the rest of the queries.
    Remove the prefix nums[0..(starti - 1)] (where nums[0..(-1)] will be used to represent the empty prefix).
    Return an array result of size queries.length where result[i] is the answer for the ith query.
    A prefix of an array is a subarray that starts from the beginning of the array and extends to any point within it.
    A suffix of an array is a subarray that starts at any point within the array and extends to the end of the array.
    Note that the prefix and suffix to be chosen for the operation can be empty.
    Note that x-value has a different definition in this version.

    Example :

    Input: nums = [1,2,3,4,5], k = 3, queries = [[2,2,0,2],[3,3,3,0],[0,1,0,1]]
    Output: [2,2,2]
    Explanation:
    For query 0, nums becomes [1, 2, 2, 4, 5], and the empty prefix must be removed. The possible operations are:
    Remove the suffix [2, 4, 5]. nums becomes [1, 2].
    Remove the empty suffix. nums becomes [1, 2, 2, 4, 5] with a product 80, which gives remainder 2 when divided by 3.
    For query 1, nums becomes [1, 2, 2, 3, 5], and the prefix [1, 2, 2] must be removed. The possible operations are:
    Remove the empty suffix. nums becomes [3, 5].
    Remove the suffix [5]. nums becomes [3].
    For query 2, nums becomes [1, 2, 2, 3, 5], and the empty prefix must be removed. The possible operations are:
    Remove the suffix [2, 2, 3, 5]. nums becomes [1].
    Remove the suffix [3, 5]. nums becomes [1, 2, 2].
 */



function resultArray(nums: number[], k: number, queries: number[][]): number[] {
    const n = nums.length;

    let size = 1;
    while (size < n) size <<= 1;

    const H: number[] = new Array(2 * size * k).fill(0);
    const prod: number[] = new Array(2 * size).fill(1 % k);

    const pull = (i: number): void => {
        const lc = 2 * i;
        const rc = lc + 1;
        const lp = prod[lc];

        const bi = i * k;
        const bl = lc * k;
        const br = rc * k;

        for (let q = 0; q < k; q++) {
            H[bi + q] = H[bl + q];
        }

        for (let q = 0; q < k; q++) {
            const c = H[br + q];

            if (c) {
                H[bi + (lp * q) % k] += c;
            }
        }

        prod[i] = (lp * prod[rc]) % k;
    };

    for (let i = 0; i < n; i++) {
        const v = nums[i] % k;
        const nd = size + i;

        H[nd * k + v] = 1;
        prod[nd] = v;
    }

    for (let i = size - 1; i >= 1; i--) {
        pull(i);
    }

    const update = (idx: number, val: number): void => {
        const nd = size + idx;
        const base = nd * k;

        for (let q = 0; q < k; q++) {
            H[base + q] = 0;
        }

        const v = val % k;

        H[base + v] = 1;
        prod[nd] = v;

        let cur = nd >> 1;

        while (cur) {
            pull(cur);
            cur >>= 1;
        }
    };

    const ans: number[] = [];

    for (const [idx, val, start, x] of queries) {
        update(idx, val);

        let l = start + size;
        let r = n + size;

        const ln: number[] = [];
        const rn: number[] = [];

        while (l < r) {
            if (l & 1) {
                ln.push(l++);
            }

            if (r & 1) {
                rn.push(--r);
            }

            l >>= 1;
            r >>= 1;
        }

        const res: number[] = new Array(k).fill(0);
        let p = 1 % k;

        for (const node of ln) {
            const base = node * k;

            for (let q = 0; q < k; q++) {
                const c = H[base + q];

                if (c) {
                    res[(p * q) % k] += c;
                }
            }

            p = (p * prod[node]) % k;
        }

        for (let i = rn.length - 1; i >= 0; i--) {
            const node = rn[i];
            const base = node * k;

            for (let q = 0; q < k; q++) {
                const c = H[base + q];

                if (c) {
                    res[(p * q) % k] += c;
                }
            }

            p = (p * prod[node]) % k;
        }

        ans.push(res[x]);
    }

    return ans;
};