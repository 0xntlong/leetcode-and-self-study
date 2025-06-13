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


#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        if (p == 0)
            return 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int l = 0;
        int r = nums[n - 1] - nums[0];
        while (l < r){
            int m = l + (r - l) / 2;
            int pairs = 0;
            for (int i = 1; i < n; i++){
                if (m >= nums[i] - nums[i - 1]){
                    pairs++;
                    i++;
                }
            }
            if (pairs >= p){
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};