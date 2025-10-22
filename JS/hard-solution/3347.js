/**
3347. Maximum Frequency of an Element After Performing Operations II
    You are given an integer array nums and two integers k and numOperations.
    You must perform an operation numOperations times on nums, where in each operation you:
    Select an index i that was not selected in any previous operations.
    Add an integer in the range [-k, k] to nums[i].
    Return the maximum possible frequency of any element in nums after performing the operations.

    Example :
    Input: nums = [1,4,5], k = 1, numOperations = 2
    Output: 2
    Explanation:
    We can achieve a maximum frequency of two by:
    Adding 0 to nums[1], after which nums becomes [1, 4, 5].
    Adding -1 to nums[2], after which nums becomes [1, 4, 4].
 */




/**
 * @param {number[]} nums
 * @param {number} k
 * @param {number} numOperations
 * @return {number}
 */
var maxFrequency = function(nums, k, numOperations) {
    if (nums.length === 0) 
        return 0;
    nums.sort((a, b) => a - b);
    const n = nums.length;
    const freq = new Map();
    for (const x of nums) 
        freq.set(x, (freq.get(x) || 0) + 1);

    let ans = 1;

    const lowerBound = (arr, target) => {
        let l = 0, r = arr.length;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (arr[mid] < target) l = mid + 1;
            else r = mid;
        }
        return l;
    };

    const upperBound = (arr, target) => {
        let l = 0, r = arr.length;
        while (l < r) {
            const mid = (l + r) >> 1;
            if (arr[mid] <= target) 
                l = mid + 1;
            else r = mid;
        }
        return l;
    };

    for (const [key, val] of freq.entries()) {
        const low = key - k, high = key + k;
        const left = lowerBound(nums, low);
        const right = upperBound(nums, high);
        const inRange = right - left;
        const visited = inRange - val;
        const minLoop = Math.min(visited, numOperations);
        ans = Math.max(ans, val + minLoop);
    }

    let l = 0;
    for (let r = 0; r < n; r++) {
        while (l <= r && nums[r] - nums[l] > 2 * k) l++;
        const w = r - l + 1;
        ans = Math.max(ans, Math.min(w, numOperations));
    }

    return ans;
};