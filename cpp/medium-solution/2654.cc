/**
2654. Minimum Number of Operations to Make All Array Elements Equal to 1
    You are given a 0-indexed array nums consisiting of positive integers. You can do the following operation on the array any number of times:
    Select an index i such that 0 <= i < n - 1 and replace either of nums[i] or nums[i+1] with their gcd value.
    Return the minimum number of operations to make all elements of nums equal to 1. If it is impossible, return -1.
    The gcd of two integers is the greatest common divisor of the two integers.

    Example :
    Input: nums = [2,6,3,4]
    Output: 4
    Explanation: We can do the following operations:
    - Choose index i = 2 and replace nums[2] with gcd(3,4) = 1. Now we have nums = [2,6,1,4].
    - Choose index i = 1 and replace nums[1] with gcd(6,1) = 1. Now we have nums = [2,1,1,4].
    - Choose index i = 0 and replace nums[0] with gcd(2,1) = 1. Now we have nums = [1,1,1,4].
    - Choose index i = 2 and replace nums[3] with gcd(1,4) = 1. Now we have nums = [1,1,1,1].
 */

#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Solution {
public:
    int gcd(int a, int b){
        if (b == 0){
            return abs(a);
        }
        return gcd(b, a % b);
    }
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int cnt1 = count(nums.begin(), nums.end(), 1);
        if (cnt1)
            return n - cnt1;
        int res = INT_MAX;
        for (int l = 0; l < n; l++){
            int g = nums[l];
            for (int r = l + 1; r < n; r++){
                g = gcd(g, nums[r]);
                if (g == 1){
                    res = min(res, r - l + (n - 1));
                    break;
                }
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};