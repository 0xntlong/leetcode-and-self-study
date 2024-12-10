/*
1995. Count Special Quadruplets
    Given a 0-indexed integer array nums, return the number of distinct quadruplets (a, b, c, d) such that:
    nums[a] + nums[b] + nums[c] == nums[d], and
    a < b < c < d

    Example :
    Input: nums = [1,2,3,6]
    Output: 1
    Explanation: The only quadruplet that satisfies the requirement is (0, 1, 2, 3) because 1 + 2 + 3 == 6.
*/

#include <vector> 
using namespace std;
class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        int count = 0;
        int n = nums.size();
        for (int a = 0; a < n; a++){
            for (int b = a + 1; b < n; b++){
                for (int c = b + 1; c < n; c++){
                    for (int d = c + 1; d < n; d++){
                        if (nums[a] + nums[b] + nums[c] == nums[d])
                            count++;
                    }
                }
            }
        }
        return count;
    }
};