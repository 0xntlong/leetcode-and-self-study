/**
3903. Smallest Stable Index I
    You are given an integer array nums of length n and an integer k.
    For each index i, define its instability score as max(nums[0..i]) - min(nums[i..n - 1]).
    In other words:
    max(nums[0..i]) is the largest value among the elements from index 0 to index i.
    min(nums[i..n - 1]) is the smallest value among the elements from index i to index n - 1.
    An index i is called stable if its instability score is less than or equal to k.
    Return the smallest stable index. If no such index exists, return -1.

    Example :
    Input: nums = [5,0,1,4], k = 3
    Output: 3
    Explanation:
    At index 0: The maximum in [5] is 5, and the minimum in [5, 0, 1, 4] is 0, so the instability score is 5 - 0 = 5.
    At index 1: The maximum in [5, 0] is 5, and the minimum in [0, 1, 4] is 0, so the instability score is 5 - 0 = 5.
    At index 2: The maximum in [5, 0, 1] is 5, and the minimum in [1, 4] is 1, so the instability score is 5 - 1 = 4.
    At index 3: The maximum in [5, 0, 1, 4] is 5, and the minimum in [4] is 4, so the instability score is 5 - 4 = 1.
    This is the first index with an instability score less than or equal to k = 3. Thus, the answer is 3.
*/


/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var firstStableIndex = function(nums, k) {
    const n = nums.length;

    const vmax = new Array(n);
    const vmin = new Array(n);

    vmax[0] = nums[0];
    vmin[n - 1] = nums[n - 1];

    for (let i = 1; i < n; i++) {
        vmax[i] = Math.max(vmax[i - 1], nums[i]);

        const idx = n - 1 - i;
        vmin[idx] = Math.min(vmin[idx + 1], nums[idx]);
    }

    for (let i = 0; i < n; i++) {
        if (vmax[i] - vmin[i] <= k) {
            return i;
        }
    }

    return -1;
};