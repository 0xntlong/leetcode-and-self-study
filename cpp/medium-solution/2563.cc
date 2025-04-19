/*
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

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        std::sort(nums.begin(), nums.end());
        long long total = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++){
            auto left = std::lower_bound(nums.begin(), nums.begin() + i, lower - nums[i]);
            auto right = std::upper_bound(nums.begin(), nums.begin() + i, upper - nums[i]);
            total += (right - left);
        }
        return total;
    }
};

// Another Approach 
/*
class Solution {
public:
    int n;
    long long cnt(vector<int>& nums, int x){
        int left = 0, right = n - 1;
        long long ans = 0;
        while(left < right){
            int s = nums[left] + nums[right];
            if (s < x){
                ans += (right - left);
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        return cnt(nums, upper + 1) - cnt(nums, lower);
    }
};
*/