/*
2501. Longest Square Streak in an Array
    You are given an integer array nums. A subsequence of nums is called a square streak if:
    The length of the subsequence is at least 2, and
    after sorting the subsequence, each element (except the first element) is the square of the previous number.
    Return the length of the longest square streak in nums, or return -1 if there is no square streak.
    A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
    
    Example :
    Input: nums = [4,3,6,16,8,2]
    Output: 3
    Explanation: Choose the subsequence [4,16,2]. After sorting it, it becomes [2,4,16].
    - 4 = 2 * 2.
    - 16 = 4 * 4.
    Therefore, [4,16,2] is a square streak.
    It can be shown that every subsequence of length 4 is not a square streak.
*/

#include <vector>
#include <unordered_set>
#include <algorithm>
class Solution {
public:
    int longestSquareStreak(std::vector<int>& nums) {
        std::unordered_set<int> nums_set(nums.begin(), nums.end());
        std::vector<int> unique_nums(nums_set.begin(), nums_set.end());
        std::sort(unique_nums.begin(), unique_nums.end());
        int max_streak = 0;
        for( int i : unique_nums){
            int streak = 0;
            long long cur = i;
            while (nums_set.find(cur) != nums_set.end()){
                streak++;
                cur *= cur;
                if ( cur > INT_MAX)
                    break;
            }
            if (streak > 1){
                max_streak = std::max(max_streak, streak);
            }
        }
        return max_streak > 1 ? max_streak : -1;
    }
};