/**
3487. Maximum Unique Subarray Sum After Deletion
    You are given an integer array nums.
    You are allowed to delete any number of elements from nums without making it empty. After performing the deletions, select a subarray of nums such that:
    All elements in the subarray are unique.
    The sum of the elements in the subarray is maximized.
    Return the maximum sum of such a subarray.

    Example :
    Input: nums = [1,2,3,4,5]
    Output: 15
    Explanation:
    Select the entire array without deleting any element to obtain the maximum sum.
 */


function maxSum(nums: number[]): number {
    const maxVal = Math.max(...nums);
    if (maxVal < 0)
        return maxVal;
    const set = new Set<number>(nums);
    let res = 0;
    for (const num of set){
        if (num >= 0){
            res += num;
        }
    }
    return res;
};