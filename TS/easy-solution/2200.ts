/**
2200. Find All K-Distant Indices in an Array
    You are given a 0-indexed integer array nums and two integers key and k. A k-distant index is an index i of nums for which there exists at least one index j such that |i - j| <= k and nums[j] == key.
    Return a list of all k-distant indices sorted in increasing order.

    Example 1:
    Input: nums = [3,4,9,1,3,9,5], key = 9, k = 1
    Output: [1,2,3,4,5,6]
    Explanation: Here, nums[2] == key and nums[5] == key.
    - For index 0, |0 - 2| > k and |0 - 5| > k, so there is no j where |0 - j| <= k and nums[j] == key. Thus, 0 is not a k-distant index.
    - For index 1, |1 - 2| <= k and nums[2] == key, so 1 is a k-distant index.
    - For index 2, |2 - 2| <= k and nums[2] == key, so 2 is a k-distant index.
    - For index 3, |3 - 2| <= k and nums[2] == key, so 3 is a k-distant index.
    - For index 4, |4 - 5| <= k and nums[5] == key, so 4 is a k-distant index.
    - For index 5, |5 - 5| <= k and nums[5] == key, so 5 is a k-distant index.
    - For index 6, |6 - 5| <= k and nums[5] == key, so 6 is a k-distant index.
    Thus, we return [1,2,3,4,5,6] which is sorted in increasing order. 
 */


function findKDistantIndices(nums: number[], key: number, k: number): number[] {
    const res: number[] = [];
    let i = 0, j = 0, n = nums.length;

    while (i < n) {
        while (i < n && nums[i] !== key)
            i++;
        while (Math.abs(i - j) > k)
            j++;
        while (i < n && j < n && Math.abs(i - j) <= k) {
            res.push(j);
            j++;
        }
        i++;
    }

    return res;
};