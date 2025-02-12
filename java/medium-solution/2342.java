/**
2342. Max Sum of a Pair With Equal Sum of Digits
    You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].
    Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

    Example :
    Input: nums = [18,43,36,13,7]
    Output: 54
    Explanation: The pairs (i, j) that satisfy the conditions are:
    - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
    - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
    So the maximum sum that we can obtain is 54.
 */

 
 class Solution {
    public int maximumSum(int[] nums) {
       int [] max = new int[100];
       int ans = -1;
       for (int x : nums){
        int total = 0;
        int temp = x;
        while (temp != 0){
            total += temp % 10;
            temp /= 10;
        }
        if (max[total] != 0)
            ans = Math.max(ans, x + max[total]);
        max[total] = Math.max(max[total], x);
        }
        return ans;
    }
}