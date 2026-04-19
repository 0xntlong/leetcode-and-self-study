/**
1855. Maximum Distance Between a Pair of Values
    You are given two non-increasing 0-indexed integer arrays nums1​​​​​​ and nums2​​​​​​.

    A pair of indices (i, j), where 0 <= i < nums1.length and 0 <= j < nums2.length, is valid if both i <= j and nums1[i] <= nums2[j]. The distance of the pair is j - i​​​​.

    Return the maximum distance of any valid pair (i, j). If there are no valid pairs, return 0.

    An array arr is non-increasing if arr[i-1] >= arr[i] for every 1 <= i < arr.length.

    

    Example 1:

    Input: nums1 = [55,30,5,4,2], nums2 = [100,20,10,10,5]
    Output: 2
    Explanation: The valid pairs are (0,0), (2,2), (2,3), (2,4), (3,3), (3,4), and (4,4).
    The maximum distance is 2 with pair (2,4).
 */


/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var maxDistance = function(nums1, nums2) {
    let i = 0;
    let res = 0;
    const n1 = nums1.length, n2 = nums2.length;

    for (let j = 0; j < n2; j++) {
        while (i < n1 && nums1[i] > nums2[j]) {
            i++;
        }
        if (i === n1) 
            break;

        res = Math.max(res, j - i);
    }

    return res;
};