/**
1590. Make Sum Divisible by P
    Given an array of positive integers nums, remove the smallest subarray (possibly empty) such that the sum of the remaining elements is divisible by p. It is not allowed to remove the whole array.
    Return the length of the smallest subarray that you need to remove, or -1 if it's impossible.
    A subarray is defined as a contiguous block of elements in the array.

    Example :
    Input: nums = [3,1,4,2], p = 6
    Output: 1
    Explanation: The sum of the elements in nums is 10, which is not divisible by 6. We can remove the subarray [4], and the sum of the remaining elements is 6, which is divisible by 6.
 */



function minSubarray(nums: number[], p: number): number {
    let total = nums.reduce((a, b) => a + b, 0);
    let target = total % p;
    if (target === 0) return 0;

    const map = new Map<number, number>();
    map.set(0, -1);

    let cur = 0;
    let res = nums.length;

    for (let i = 0; i < nums.length; i++) {
        cur = (cur + nums[i]) % p;
        const need = (cur - target + p) % p;

        if (map.has(need)) {
            res = Math.min(res, i - map.get(need)!);
        }

        map.set(cur, i);
    }

    return res === nums.length ? -1 : res;
};