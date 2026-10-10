/**
2333. Minimum Sum of Squared Difference
    You are given two positive 0-indexed integer arrays nums1 and nums2, both of length n.
    The sum of squared difference of arrays nums1 and nums2 is defined as the sum of (nums1[i] - nums2[i])2 for each 0 <= i < n.
    You are also given two positive integers k1 and k2. You can modify any of the elements of nums1 by +1 or -1 at most k1 times. Similarly, you can modify any of the elements of nums2 by +1 or -1 at most k2 times.
    Return the minimum sum of squared difference after modifying array nums1 at most k1 times and modifying array nums2 at most k2 times.
    Note: You are allowed to modify the array elements to become negative integers.

    Example :
    Input: nums1 = [1,2,3,4], nums2 = [2,10,20,19], k1 = 0, k2 = 0
    Output: 579
    Explanation: The elements in nums1 and nums2 cannot be modified because k1 = 0 and k2 = 0. 
    The sum of square difference will be: (1 - 2)2 + (2 - 10)2 + (3 - 20)2 + (4 - 19)2 = 579.
 */


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number} k1
 * @param {number} k2
 * @return {number}
 */
var minSumSquareDiff = function(nums1, nums2, k1, k2) {
    let k = k1 + k2;
    const n = nums1.length;
    const d = [];

    let total = 0;

    for (let i = 0; i < n; i++) {
        d.push(Math.abs(nums1[i] - nums2[i]));
        total += d[i];
    }

    if (total <= k)
        return 0;

    d.sort((a, b) => b - a);
    d.push(0);

    for (let i = 1; i <= n; i++) {
        const cost = (d[i - 1] - d[i]) * i;

        if (cost > k) {
            const q = Math.floor(k / i);
            const r = k % i;
            const hi = d[i - 1] - q;

            let res = hi * hi * (i - r)
                    + (hi - 1) * (hi - 1) * r;

            for (let j = i; j < n; j++)
                res += d[j] * d[j];

            return res;
        }

        k -= cost;
    }

    return 0;
};