/**
3719. Longest Balanced Subarray I
    You are given an integer array nums.
    A subarray is called balanced if the number of distinct even numbers in the subarray is equal to the number of distinct odd numbers.
    Return the length of the longest balanced subarray.

    Example :
    Input: nums = [2,5,4,3]
    Output: 4
    Explanation:
    The longest balanced subarray is [2, 5, 4, 3].
    It has 2 distinct even numbers [2, 4] and 2 distinct odd numbers [5, 3]. Thus, the answer is 4.
 */


function longestBalancedI(nums: number[]): number {
    const n = nums.length;
    let res = 0;
    for (let i = 0; i < n; i++) {
        if (res > n - i) 
            break;

        const visited = new Set<number>();
        let balance = 0;

        for (let j = i; j < n; j++) {
            const num = nums[j];
            if (!visited.has(num)) {
                balance += (num % 2 === 0) ? 1 : -1;
                visited.add(num);
            }
            if (balance === 0) 
                res = Math.max(res, j - i + 1);
        }
    }
    return res;
};