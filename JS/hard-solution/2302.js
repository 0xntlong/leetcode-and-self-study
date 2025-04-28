/**
2302. Count Subarrays With Score Less Than K
    The score of an array is defined as the product of its sum and its length.
    For example, the score of [1, 2, 3, 4, 5] is (1 + 2 + 3 + 4 + 5) * 5 = 75.
    Given a positive integer array nums and an integer k, return the number of non-empty subarrays of nums whose score is strictly less than k.
    A subarray is a contiguous sequence of elements within an array.

    Example :
    Input: nums = [2,1,4,3,5], k = 10
    Output: 6
    Explanation:
    The 6 subarrays having scores less than 10 are:
    - [2] with score 2 * 1 = 2.
    - [1] with score 1 * 1 = 1.
    - [4] with score 4 * 1 = 4.
    - [3] with score 3 * 1 = 3. 
    - [5] with score 5 * 1 = 5.
    - [2,1] with score (2 + 1) * 2 = 6.
    Note that subarrays such as [1,4] and [4,3,5] are not considered because their scores are 10 and 36 respectively, while we need scores strictly less than 10.
 */

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number}
 */
var countSubarrays = function(nums, k) {
    let total = 0, count = 0;
    let n = nums.length;
    let left = 0;
    for (let right = 0; right < n; right++){
        total += nums[right];
   
        while (total * (right - left + 1) >= k){
            total -= nums[left];
            left++;
        }
        count += (right - left + 1);
    }
    return count;
};