/**
3739. Count Subarrays With Majority Element II
    You are given an integer array nums and an integer target.
    Return the number of subarrays of nums in which target is the majority element.
    The majority element of a subarray is the element that appears strictly more than half of the times in that subarray.

    Example :
    Input: nums = [1,2,2,3], target = 2
    Output: 5
    Explanation:
    Valid subarrays with target = 2 as the majority element:
    nums[1..1] = [2]
    nums[2..2] = [2]
    nums[1..2] = [2,2]
    nums[0..2] = [1,2,2]
    nums[1..3] = [2,2,3]
    So there are 5 such subarrays.
 */



function countMajoritySubarrays(nums: number[], target: number): number {
    const n = nums.length;
    const freq: number[] = Array(2 * n + 1).fill(0);

    freq[n] = 1;

    let idx = n;
    let res = 0;
    let pref = 0;

    for (const x of nums) {
        if (x === target) {
            pref += freq[idx];
            idx++;
        } else {
            idx--;
            pref -= freq[idx];
        }

        freq[idx]++;
        res += pref;
    }

    return res;
}