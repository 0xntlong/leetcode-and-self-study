/**
3718. Smallest Missing Multiple of K
    Given an integer array nums and an integer k, return the smallest positive multiple of k that is missing from nums.
    A multiple of k is any positive integer divisible by k.
    Example :
    Input: nums = [8,2,3,4,6], k = 2
    Output: 10
    Explanation:
    The multiples of k = 2 are 2, 4, 6, 8, 10, 12... and the smallest multiple missing from nums is 10.
 */



/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var missingMultiple = function(nums, k) {
    const hashSet = new Set(nums);

    let i = 1;

    while (true) {
        if (!hashSet.has(i * k)) {
            return i * k;
        }

        i++;
    }
};