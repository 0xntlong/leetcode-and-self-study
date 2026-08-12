/**
2958. Length of Longest Subarray With at Most K Frequency
    You are given an integer array nums and an integer k.
    The frequency of an element x is the number of times it occurs in an array.
    An array is called good if the frequency of each element in this array is less than or equal to k.
    Return the length of the longest good subarray of nums.
    A subarray is a contiguous non-empty sequence of elements within an array.

    Example :
    Input: nums = [1,2,3,1,2,3,1,2], k = 2
    Output: 6
    Explanation: The longest possible good subarray is [1,2,3,1,2,3] since the values 1, 2, and 3 occur at most twice in this subarray. Note that the subarrays [2,3,1,2,3,1] and [3,1,2,3,1,2] are also good.
    It can be shown that there are no good subarrays with length more than 6.
 */



function maxSubarrayLength(nums: number[], k: number): number {
    let left: number = 0;
    let res: number = 0;

    const count: Map<number, number> = new Map();
    const n: number = nums.length;

    for (let i = 0; i < n; i++) {
        count.set(
            nums[i],
            (count.get(nums[i]) ?? 0) + 1
        );

        while ((count.get(nums[i]) ?? 0) > k) {
            count.set(
                nums[left],
                (count.get(nums[left]) ?? 0) - 1
            );

            left++;
        }

        res = Math.max(res, i - left + 1);
    }

    return res;
};