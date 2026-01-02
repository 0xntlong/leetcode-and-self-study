/**
961. N-Repeated Element in Size 2N Array
    You are given an integer array nums with the following properties:
    nums.length == 2 * n.
    nums contains n + 1 unique elements.
    Exactly one element of nums is repeated n times.
    Return the element that is repeated n times.

    Example :
    Input: nums = [1,2,3,3]
    Output: 3
 */


function repeatedNTimes(nums: number[]): number {
    const set = new Set<number>();
    for (const i of nums){
        if (set.has(i)){
            return i;
        }
        set.add(i);
    }
    return -1;
};