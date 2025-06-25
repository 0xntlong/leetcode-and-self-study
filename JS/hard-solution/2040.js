/**
2040. Kth Smallest Product of Two Sorted Arrays
    Given two sorted 0-indexed integer arrays nums1 and nums2 as well as an integer k, return the kth (1-based) smallest product of nums1[i] * nums2[j] where 0 <= i < nums1.length and 0 <= j < nums2.length.

    Example :
    Input: nums1 = [2,5], nums2 = [3,4], k = 2
    Output: 8
    Explanation: The 2 smallest products are:
    - nums1[0] * nums2[0] = 2 * 3 = 6
    - nums1[0] * nums2[1] = 2 * 4 = 8
    The 2nd smallest product is 8.
 */



/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @param {number} k
 * @return {number}
 */
var kthSmallestProduct = function(nums1, nums2, k) {
    let left = -1e10, right = 1e10;
    while (left < right){
        const mid = Math.floor((left + right) / 2);
        if (countPair(nums1, nums2, mid) < k){
            left = mid + 1;
        }
        else 
            right = mid;
    }
    return left;
};
function countPair(nums1, nums2, target){
    let count = 0;
    for (const n1 of nums1){
        if (n1 === 0){
            if (target >= 0){
                count += nums2.length;
            }
            continue;
        }
        let low = 0, high = nums2.length;
        if (n1 > 0){
            while (low < high){
                const mid = Math.floor((low + high) / 2);
                if (n1 * nums2[mid] <= target){
                    low = mid + 1;
                } else {
                    high = mid;
                }
            }
            count += low;
        } else {
            while (low < high){
                const mid = Math.floor((low + high) / 2);
                if (n1 * nums2[mid] <= target)
                    high = mid;
                else
                    low = mid + 1;
            }
            count += nums2.length - low;
        }
    }
    return count;
}