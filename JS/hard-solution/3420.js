/**
3420. Count Non-Decreasing Subarrays After K Operations
    You are given an array nums of n integers and an integer k.
    For each subarray of nums, you can apply up to k operations on it. In each operation, you increment any element of the subarray by 1.
    Note that each subarray is considered independently, meaning changes made to one subarray do not persist to another.
    Return the number of subarrays that you can make non-decreasing ​​​​​after performing at most k operations.
    An array is said to be non-decreasing if each element is greater than or equal to its previous element, if it exists.

    Example :
    Input: nums = [6,3,1,2,4,4], k = 7
    Output: 17
    Explanation:
    Out of all 21 possible subarrays of nums, only the subarrays [6, 3, 1], [6, 3, 1, 2], [6, 3, 1, 2, 4] and [6, 3, 1, 2, 4, 4] cannot be made non-decreasing after applying up to k = 7 operations. Thus, the number of non-decreasing subarrays is 21 - 4 = 17.
 */



/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countNonDecreasingSubarrays = function(nums, k) {
    const n = nums.length;
    let right = n - 1;
    let total_cost = 0;
    let res = 0;

    const q = new Array(2 * n + 1);
    let head = n;
    let tail = n;

    for (let left = n - 1; left >= 0; left--) {
        const x = nums[left];
        let c = 1;

        while (head < tail && q[head][0] < x) {
            const [value, count] = q[head++];

            total_cost += (x - value) * count;
            c += count;
        }

        q[--head] = [x, c];

        while (total_cost > k) {
            const [value, count] = q[--tail];

            total_cost -= value - nums[right];
            right--;

            if (count > 1) {
                q[tail++] = [value, count - 1];
            }
        }

        res += right - left + 1;
    }

    return res;
};