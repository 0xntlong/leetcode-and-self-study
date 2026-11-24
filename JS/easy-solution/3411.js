/**
3411. Maximum Subarray With Equal Products
    You are given an array of positive integers nums.
    An array arr is called product equivalent if prod(arr) == lcm(arr) * gcd(arr), where:
    prod(arr) is the product of all elements of arr.
    gcd(arr) is the GCD of all elements of arr.
    lcm(arr) is the LCM of all elements of arr.
    Return the length of the longest product equivalent subarray of nums.

    Example 1:
    Input: nums = [1,2,1,2,1,1,1]
    Output: 5
    Explanation: 
    The longest product equivalent subarray is [1, 2, 1, 1, 1], where prod([1, 2, 1, 1, 1]) = 2, gcd([1, 2, 1, 1, 1]) = 1, and lcm([1, 2, 1, 1, 1]) = 2.
 */



/**
 * @param {number[]} nums
 * @return {number}
 */
var maxLength = function(nums) {
    const MASKS = [0, 0, 1, 2, 1, 4, 3, 8, 1, 2, 5];

    let res = Math.min(nums.length, 2);
    let window_mask = 0;
    let start = 0;

    for (let end = 0; end < nums.length; end++) {
        const m = MASKS[nums[end]];

        while (window_mask & m) {
            window_mask ^= MASKS[nums[start]];
            start++;
        }

        window_mask |= m;

        const curr_len = end - start + 1;
        if (curr_len > res) {
            res = curr_len;
        }
    }
    return res;
};