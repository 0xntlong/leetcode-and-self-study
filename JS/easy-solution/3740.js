/**
3740. Minimum Distance Between Three Equal Elements I
    You are given an integer array nums.
    A tuple (i, j, k) of 3 distinct indices is good if nums[i] == nums[j] == nums[k].
    The distance of a good tuple is abs(i - j) + abs(j - k) + abs(k - i), where abs(x) denotes the absolute value of x.
    Return an integer denoting the minimum possible distance of a good tuple. If no good tuples exist, return -1.
    Example :
    Input: nums = [1,2,1,1,3]
    Output: 6
    Explanation:
    The minimum distance is achieved by the good tuple (0, 2, 3).
    (0, 2, 3) is a good tuple because nums[0] == nums[2] == nums[3] == 1. Its distance is abs(0 - 2) + abs(2 - 3) + abs(3 - 0) = 2 + 1 + 3 = 6.
 */


/**
 * @param {number[]} nums
 * @return {number}
 */
var minimumDistance = function(nums) {
    const maxVal = Math.max(...nums);
    const pos = Array.from({ length: maxVal + 1 }, () => [-1, -1]);
    
    let res = Infinity;

    for (let i = 0; i < nums.length; i++) {
        const val = nums[i];
        const [last, secondLast] = pos[val];

        if (secondLast !== -1) {
            const distance = (i - secondLast) * 2;
            res = Math.min(res, distance);
        }

        pos[val] = [i, last];
    }

    return res === Infinity ? -1 : res;
};