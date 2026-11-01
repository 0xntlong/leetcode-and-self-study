/**
453. Minimum Moves to Equal Array Elements
    Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.
    In one move, you can increment n - 1 elements of the array by 1.

    Example :
    Input: nums = [1,2,3]
    Output: 3
    Explanation: Only three moves are needed (remember each move increments two elements):
    [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
 */


class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int count = 0;

        for (int i = nums.size() - 1; i > 0; i--) {
            count += nums[i] - nums[0];
        }

        return count;
    }
};