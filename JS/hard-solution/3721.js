/**
3721. Longest Balanced Subarray II
    You are given an integer array nums.
    A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.
    Return the length of the longest balanced subarray.

    Example :
    Input: nums = [2,5,4,3]
    Output: 4
    Explanation:
    The longest balanced subarray is [2, 5, 4, 3].
    It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [5, 3]. Thus, the answer is 4.
 */



/**
 * @param {number[]} nums
 * @return {number}
 */
var longestBalanced = function(nums) {
    const n = nums.length;
    const mn = new Int32Array(4 * n + 5);
    const mx = new Int32Array(4 * n + 5);
    const lz = new Int32Array(4 * n + 5);

    const push = (node) => {
        const val = lz[node];
        if (val === 0) 
            return;

        const lc = node << 1;
        const rc = lc | 1;

        mn[lc] += val; mx[lc] += val; lz[lc] += val;
        mn[rc] += val; mx[rc] += val; lz[rc] += val;

        lz[node] = 0;
    };

    const pull = (node) => {
        const lc = node << 1;
        const rc = lc | 1;
        mn[node] = Math.min(mn[lc], mn[rc]);
        mx[node] = Math.max(mx[lc], mx[rc]);
    };

    const update = (node, segLeft, segRight, queryLeft, queryRight, addValue) => {
        if (queryLeft > queryRight) 
            return;

        if (queryLeft === segLeft && queryRight === segRight) {
            mn[node] += addValue;
            mx[node] += addValue;
            lz[node] += addValue;
            return;
        }

        push(node);
        const mid = (segLeft + segRight) >> 1;

        update(node << 1, segLeft, mid, queryLeft, Math.min(queryRight, mid), addValue);
        update(node << 1 | 1, mid + 1, segRight, Math.max(queryLeft, mid + 1), queryRight, addValue);

        pull(node);
    };

    const findFirst = (node, segLeft, segRight, limit) => {
        if (segLeft > limit) 
            return -1;
        if (mn[node] > 0 || mx[node] < 0) 
            return -1;
        if (segLeft === segRight) 
            return segLeft;

        push(node);
        const mid = (segLeft + segRight) >> 1;

        const leftRes = findFirst(node << 1, segLeft, mid, limit);
        if (leftRes !== -1) 
            return leftRes;

        if (mid < limit) 
            return findFirst(node << 1 | 1, mid + 1, segRight, limit);
        return -1;
    };

    const lastPos = new Int32Array(100005);
    lastPos.fill(-1);

    let maxLen = 0;
    for (let i = 0; i < n; i++) {
        const val = nums[i];
        const prev = lastPos[val];
        const diff = (val & 1) ? -1 : 1;

        update(1, 0, n - 1, prev + 1, i, diff);

        lastPos[val] = i;

        const start = findFirst(1, 0, n - 1, i);
        if (start !== -1) {
            maxLen = Math.max(maxLen, i - start + 1);
        }
    }
    return maxLen;
};