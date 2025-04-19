/**
2563. Count the Number of Fair Pairs
    Given a 0-indexed integer array nums of size n and two integers lower and upper, return the number of fair pairs.
    A pair (i, j) is fair if:
    0 <= i < j < n, and
    lower <= nums[i] + nums[j] <= upper
    
    Example :
    Input: nums = [0,1,7,4,4,5], lower = 3, upper = 6
    Output: 6
    Explanation: There are 6 fair pairs: (0,3), (0,4), (0,5), (1,3), (1,4), and (1,5).
 */

    function countFairPairs(nums: number[], lower: number, upper: number): number {
        nums.sort((a, b) => a - b);
        const cnt = (nums: number[], x: number): number => {
            let left = 0, right = nums.length - 1;
            let ans = 0;
            while (left < right){
                let sum = nums[left] + nums[right];
                if (sum < x){
                    ans += (right - left);
                    left++;
                } else {
                    right--;
                }
            }
            return ans;
        };
        return cnt(nums, upper + 1) - cnt(nums, lower);
    };