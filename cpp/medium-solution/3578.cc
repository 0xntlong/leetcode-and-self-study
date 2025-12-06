/**
3578. Count Partitions With Max-Min Difference at Most K
    You are given an integer array nums and an integer k. Your task is to partition nums into one or more non-empty contiguous segments such that in each segment, the difference between its maximum and minimum elements is at most k.

    Return the total number of ways to partition nums under this condition.

    Since the answer may be too large, return it modulo 109 + 7.

    

    Example 1:

    Input: nums = [9,4,1,3,7], k = 4

    Output: 6

    Explanation:

    There are 6 valid partitions where the difference between the maximum and minimum elements in each segment is at most k = 4:

    [[9], [4], [1], [3], [7]]
    [[9], [4], [1], [3, 7]]
    [[9], [4], [1, 3], [7]]
    [[9], [4, 1], [3], [7]]
    [[9], [4, 1], [3, 7]]
    [[9], [4, 1, 3], [7]]
*/
#include <vector>
#include <deque>
using namespace std;


class Solution {
public:
    int countPartitions(vector<int>& nums, int k) {
        const int mod = 1e9 + 7;
        int n = nums.size();
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        deque<int> maxq, minq;
        int left = 0;
        long long total = 0;
        for (int i = 0; i < n; i++){
            while (!maxq.empty() && nums[maxq.back()] <= nums[i]){
                maxq.pop_back();
            }

            while (!minq.empty() && nums[minq.back()] >= nums[i]){
                minq.pop_back();
            }
            maxq.push_back(i);
            minq.push_back(i);

            while (nums[maxq.front()] - nums[minq.front()] > k){
                if (maxq.front() == left)
                    maxq.pop_front();
                if (minq.front() == left)
                    minq.pop_front();
                total = (total - dp[left] + mod) % mod;
                left++;
            }
            total = (total + dp[i]) % mod;
            dp[i + 1] = total;
        }
        return dp[n];
    }
};