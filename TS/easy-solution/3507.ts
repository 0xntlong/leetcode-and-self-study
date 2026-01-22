/**
3507. Minimum Pair Removal to Sort Array I
    Given an array nums, you can perform the following operation any number of times:
    Select the adjacent pair with the minimum sum in nums. If multiple such pairs exist, choose the leftmost one.
    Replace the pair with their sum.
    Return the minimum number of operations needed to make the array non-decreasing.
    An array is said to be non-decreasing if each element is greater than or equal to its previous element (if it exists).

    Example :
    Input: nums = [5,2,3,1]
    Output: 2
    Explanation:
    The pair (3,1) has the minimum sum of 4. After replacement, nums = [5,2,4].
    The pair (2,4) has the minimum sum of 6. After replacement, nums = [5,6].
    The array nums became non-decreasing in two operations.
 */



function minimumPairRemoval(nums: number[]): number {
    const is_sorted = (arr: number[]): boolean => {
        for (let i = 1; i < arr.length; i++) {
            if (arr[i] < arr[i - 1]) 
                return false;
        }
        return true;
    };
    let opt = 0;
    while (!is_sorted(nums)) {
        const n = nums.length;
        let min_sum = Number.POSITIVE_INFINITY;
        let idx = 0;
        for (let i = 0; i < n - 1; i++) {
            const pair_sum = nums[i] + nums[i + 1];
            if (pair_sum < min_sum) {
                min_sum = pair_sum;
                idx = i;
            }
        }
        nums[idx] = min_sum;
        nums.splice(idx + 1, 1);
        opt++;
    }
    return opt;
};