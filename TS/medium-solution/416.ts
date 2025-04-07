/**
416. Partition Equal Subset Sum
    Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
    Example :
    Input: nums = [1,5,11,5]
    Output: true
    Explanation: The array can be partitioned as [1, 5, 5] and [11].
 */


    function canPartition(nums: number[]): boolean {
        let sum = nums.reduce((a, b) => a + b, 0);
        if (sum % 2 !== 0)
            return false;
        let mid = sum / 2;
        let dp : boolean[] = new Array(mid + 1).fill(false);
        dp[0] = true;
        for (let num of nums){
            for (let i = mid; i >= num; i--){
                dp[i] = dp[i] || dp[i - num];
            }
            if (dp[mid])
                return true;
        }
        return dp[mid];
    };