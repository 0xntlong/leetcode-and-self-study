/**
3637. Trionic Array I
    You are given an integer array nums of length n.
    An array is trionic if there exist indices 0 < p < q < n − 1 such that:
    nums[0...p] is strictly increasing,
    nums[p...q] is strictly decreasing,
    nums[q...n − 1] is strictly increasing.
    Return true if nums is trionic, otherwise return false.

    Example :
    Input: nums = [1,3,5,4,2,6]
    Output: true
    Explanation:
    Pick p = 2, q = 4:
    nums[0...2] = [1, 3, 5] is strictly increasing (1 < 3 < 5).
    nums[2...4] = [5, 4, 2] is strictly decreasing (5 > 4 > 2).
    nums[4...5] = [2, 6] is strictly increasing (2 < 6).

 */



/**
 * @param {number[]} nums
 * @return {boolean}
 */
var isTrionic = function(nums) {
    const n = nums.length;
    if (n < 3) 
        return false;

    let p = 0;
    while (p + 1 < n && nums[p] < nums[p + 1]) {
        p++;
    }
    if (p === 0 || p > n - 3) 
        return false;

    let q = p;
    while (q + 1 < n && nums[q] > nums[q + 1]) {
        q++;
    }
    if (q === p || q >= n - 1) 
        return false;

    for (let i = q; i + 1 < n; i++) {
        if (nums[i] >= nums[i + 1]) 
            return false;
    }
    return true;
};