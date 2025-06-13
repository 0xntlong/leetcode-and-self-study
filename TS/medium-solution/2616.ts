/**
2616. Minimize the Maximum Difference of Pairs
    You are given a 0-indexed integer array nums and an integer p. Find p pairs of indices of nums such that the maximum difference amongst all the pairs is minimized. Also, ensure no index appears more than once amongst the p pairs.
    Note that for a pair of elements at the index i and j, the difference of this pair is |nums[i] - nums[j]|, where |x| represents the absolute value of x.
    Return the minimum maximum difference among all p pairs. We define the maximum of an empty set to be zero.

    Example :
    Input: nums = [10,1,2,7,1,3], p = 2
    Output: 1
    Explanation: The first pair is formed from the indices 1 and 4, and the second pair is formed from the indices 2 and 5. 
    The maximum difference is max(|nums[1] - nums[4]|, |nums[2] - nums[5]|) = max(0, 1) = 1. Therefore, we return 1.
 */



function minimizeMax(nums: number[], p: number): number {
    if (p === 0)
        return 0
    nums.sort((a, b) => a - b);
    const n = nums.length;
    let left = 0;
    let right = nums[n - 1] - nums[0];
    while (left < right){
        const mid = Math.floor((left + right) / 2);
        let pairs = 0;
        for (let i = 0; i < n; i++){
            if (nums[i] - nums[i - 1] <= mid){
                pairs++;
                i++;
            }
        }
        if (pairs >= p){
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
};