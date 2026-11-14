/**
3364. Minimum Positive Sum Subarray 
    You are given an integer array nums and two integers l and r. Your task is to find the minimum sum of a subarray whose size is between l and r (inclusive) and whose sum is greater than 0.
    Return the minimum sum of such a subarray. If no such subarray exists, return -1.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example :
    Input: nums = [3, -2, 1, 4], l = 2, r = 3
    Output: 1
    Explanation:
    The subarrays of length between l = 2 and r = 3 where the sum is greater than 0 are:
    [3, -2] with a sum of 1
    [1, 4] with a sum of 5
    [3, -2, 1] with a sum of 2
    [-2, 1, 4] with a sum of 3
    Out of these, the subarray [3, -2] has a sum of 1, which is the smallest positive sum. Hence, the answer is 1.
 */



function minimumSumSubarray(nums: number[], l: number, r: number): number {
    let min_sum = Infinity;

    for (let size = l; size <= r; size++) {
        let total = 0;

        for (let i = 0; i < size; i++) {
            total += nums[i];
        }

        if (total > 0) {
            min_sum = Math.min(min_sum, total);
        }

        for (let right = size; right < nums.length; right++) {
            total = total + nums[right] - nums[right - size];

            if (total > 0) {
                min_sum = Math.min(min_sum, total);
            }
        }
    }

    return min_sum === Infinity ? -1 : min_sum;
};